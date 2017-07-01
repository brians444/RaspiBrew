/***************************************************************************
 *   Copyright (C) 2006-2008 by Tomasz Ziobrowski                          *
 *   http://www.3electrons.com                                             *
 *   e-mail: t.ziobrowski@3electrons.com                                   *
 *                                                                         *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include <QtPlugin>
#include "analogwidgets_plugin.h"
#include "defines.h"

#include "wallclock_plugin.h"
#include "manometer_plugin.h"
#include "thermometer_plugin.h" 
#include "chart_plugin.h" 
#include "bitmapbutton_plugin.h" 
//#include "wheel/wheel_plugin.h"
//#include "mnemonicbox_plugin.h" 
#include "led_plugin.h"
#include "counter_plugin.h" 
#include "scriptwidget_plugin.h" 
#include "potentiometer_plugin.h" 


#include <qglobal.h>
#include <qaction.h>
#include <QtPlugin>
#include <QDesignerFormEditorInterface>
#include <QDesignerFormWindowInterface>
#include <QDesignerFormWindowCursorInterface>
#include <QExtensionManager>
#include <QErrorMessage>


using namespace AnalogWidgetPlugin;

CustomWidgetInterface::CustomWidgetInterface( QObject *parent ):
    QObject( parent ),
    d_isInitialized( false )
{
}

bool CustomWidgetInterface::isContainer() const
{
    return false;
}

bool CustomWidgetInterface::isInitialized() const
{
    return d_isInitialized;
}

QIcon CustomWidgetInterface::icon() const
{
    return d_icon;
}

QString CustomWidgetInterface::codeTemplate() const
{
    return d_codeTemplate;
}

QString CustomWidgetInterface::domXml() const
{
    return d_domXml;
}

QString CustomWidgetInterface::group() const
{
    return "Analog Widgets";
}

QString CustomWidgetInterface::includeFile() const
{
    return d_include;
}

QString CustomWidgetInterface::name() const
{
    return d_name;
}

QString CustomWidgetInterface::toolTip() const
{
    return d_toolTip;
}

QString CustomWidgetInterface::whatsThis() const
{
    return d_whatsThis;
}

void CustomWidgetInterface::initialize(
    QDesignerFormEditorInterface *formEditor )
{
    if ( d_isInitialized )
        return;

    QExtensionManager *manager = formEditor->extensionManager();
    if ( manager )
    {
        manager->registerExtensions( new TaskMenuFactory( manager ),
            Q_TYPEID( QDesignerTaskMenuExtension ) );
    }

    d_isInitialized = true;
}


CustomWidgetCollectionInterface::CustomWidgetCollectionInterface(
        QObject *parent ):
    QObject( parent )
{
#ifndef NO_QWT_PLOT
    d_plugins.append( new PlotInterface( this ) );

#if 0
    // better not: the designer crashes TODO ..
    d_plugins.append( new PlotCanvasInterface( this ) );
#endif

    d_plugins.append( new ScaleWidgetInterface( this ) );
#endif

#ifndef NO_QWT_DIAL
    d_plugins.append( new AnalogClockInterface( this ) );
    d_plugins.append( new CompassInterface( this ) );
    d_plugins.append( new CounterInterface( this ) );
    d_plugins.append( new DialInterface( this ) );
    d_plugins.append( new KnobInterface( this ) );
    d_plugins.append( new SliderInterface( this ) );
    d_plugins.append( new ThermoInterface( this ) );
    d_plugins.append( new WheelInterface( this ) );
#endif
    d_plugins.append( new ThermoInterface( this ) );

    //d_plugins.append( new TextLabelInterface( this ) );
}

/*
TextLabelInterface::TextLabelInterface( QObject *parent ):
    CustomWidgetInterface( parent )
{
    d_name = "QwtTextLabel";
    d_include = "qwt_text_label.h";

    d_icon = QPixmap( ":/pixmaps/qwtwidget.png" );
    d_domXml =
        "<widget class=\"QwtTextLabel\" name=\"TextLabel\">\n"
        " <property name=\"geometry\">\n"
        "  <rect>\n"
        "   <x>0</x>\n"
        "   <y>0</y>\n"
        "   <width>100</width>\n"
        "   <height>20</height>\n"
        "  </rect>\n"
        " </property>\n"
        "</widget>\n";
}

QWidget *TextLabelInterface::createWidget( QWidget *parent )
{
    return new QLabel( QString( "Label" ), parent );
}
*/

QList<QDesignerCustomWidgetInterface*>
CustomWidgetCollectionInterface::customWidgets( void ) const
{
    return d_plugins;
}


// TASK


TaskMenuFactory::TaskMenuFactory( QExtensionManager *parent ):
    QExtensionFactory( parent )
{
}

QObject *TaskMenuFactory::createExtension(
    QObject *object, const QString &iid, QObject *parent ) const
{
    if ( iid == Q_TYPEID( QDesignerTaskMenuExtension ) )
    {
#ifndef NO_QWT_PLOT
        if ( QwtPlot *plot = qobject_cast<QwtPlot*>( object ) )
            return new TaskMenuExtension( plot, parent );
#endif
#ifndef NO_QWT_DIAL
        if ( QwtDial *dial = qobject_cast<QwtDial*>( object ) )
            return new TaskMenuExtension( dial, parent );
#endif
    }

    return QExtensionFactory::createExtension( object, iid, parent );
}

// TASK


TaskMenuExtension::TaskMenuExtension( QWidget *widget, QObject *parent ):
    QObject( parent ),
    d_widget( widget )
{
    d_editAction = new QAction( tr( "Edit Qwt Attributes ..." ), this );
    connect( d_editAction, SIGNAL( triggered() ),
        this, SLOT( editProperties() ) );
}

QList<QAction *> TaskMenuExtension::taskActions() const
{
    QList<QAction *> list;
    list.append( d_editAction );
    return list;
}

QAction *TaskMenuExtension::preferredEditAction() const
{
    return d_editAction;
}

void TaskMenuExtension::editProperties()
{
    const QVariant v = d_widget->property( "propertiesDocument" );
    if ( v.type() != QVariant::String )
        return;

#ifndef NO_QWT_PLOT
    QString properties = v.toString();

    if ( qobject_cast<QwtPlot*>( d_widget ) )
    {
        PlotDialog dialog( properties );
        connect( &dialog, SIGNAL( edited( const QString& ) ),
            SLOT( applyProperties( const QString & ) ) );
        ( void )dialog.exec();
        return;
    }
#endif

    static QErrorMessage *errorMessage = NULL;
    if ( errorMessage == NULL )
        errorMessage = new QErrorMessage();
    errorMessage->showMessage( "Not implemented yet." );
}

void TaskMenuExtension::applyProperties( const QString &properties )
{
    QDesignerFormWindowInterface *formWindow =
        QDesignerFormWindowInterface::findFormWindow( d_widget );
    if ( formWindow && formWindow->cursor() )
        formWindow->cursor()->setProperty( "propertiesDocument", properties );
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2( QwtDesignerPlugin, CustomWidgetCollectionInterface )
#endif


