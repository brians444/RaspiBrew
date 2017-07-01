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

#ifndef ANALOGWIDGETS_PLUGIN_H
#define ANALOGWIDGETS_PLUGIN_H

#include <QDesignerCustomWidgetInterface>
#include <QDesignerTaskMenuExtension>
#include <QExtensionFactory>

#include <QLabel>

//#include <QDesignerCustomWidgetCollectionInterface>
//#include <QList>

#define NO_QWT_PLOT
#define NO_QWT_DIAL

namespace AnalogWidgetPlugin
{
    class CustomWidgetInterface: public QObject,
            public QDesignerCustomWidgetInterface
        {
            Q_OBJECT
            Q_INTERFACES( QDesignerCustomWidgetInterface )

        public:
            CustomWidgetInterface( QObject *parent );

            virtual bool isContainer() const;
            virtual bool isInitialized() const;
            virtual QIcon icon() const;
            virtual QString codeTemplate() const;
            virtual QString domXml() const;
            virtual QString group() const;
            virtual QString includeFile() const;
            virtual QString name() const;
            virtual QString toolTip() const;
            virtual QString whatsThis() const;
            virtual void initialize( QDesignerFormEditorInterface * );

        protected:
            QString d_name;
            QString d_include;
            QString d_toolTip;
            QString d_whatsThis;
            QString d_domXml;
            QString d_codeTemplate;
            QIcon d_icon;

        private:
            bool d_isInitialized;
        };

        class CustomWidgetCollectionInterface: public QObject,
            public QDesignerCustomWidgetCollectionInterface
        {
            Q_OBJECT
            Q_INTERFACES( QDesignerCustomWidgetCollectionInterface )

    #if QT_VERSION >= 0x050000
            Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetCollectionInterface" )
    #endif


        public:
            CustomWidgetCollectionInterface( QObject *parent = NULL );

            virtual QList<QDesignerCustomWidgetInterface*> customWidgets() const;

        private:
            QList<QDesignerCustomWidgetInterface*> d_plugins;
        };

        /*
        class TextLabelInterface: public CustomWidgetInterface
        {
            Q_OBJECT
            Q_INTERFACES( QDesignerCustomWidgetInterface )

        public:
            TextLabelInterface( QObject *parent );
            virtual QWidget *createWidget( QWidget *parent );
        };*/

#ifndef NO_QWT_WIDGETS
    class ThermoInterface: public CustomWidgetInterface
    {
        Q_OBJECT
        Q_INTERFACES( QDesignerCustomWidgetInterface )

    public:
        ThermoInterface( QObject *parent );
        virtual QWidget *createWidget( QWidget *parent );
    };
#endif


    class TaskMenuFactory: public QExtensionFactory
    {
        Q_OBJECT

    public:
        TaskMenuFactory( QExtensionManager *parent = 0 );

    protected:
        QObject *createExtension( QObject *object,
            const QString &iid, QObject *parent ) const;
    };

    class TaskMenuExtension: public QObject,
        public QDesignerTaskMenuExtension
    {
        Q_OBJECT
        Q_INTERFACES( QDesignerTaskMenuExtension )

    public:
        TaskMenuExtension( QWidget *widget, QObject *parent );

        QAction *preferredEditAction() const;
        QList<QAction *> taskActions() const;

    private Q_SLOTS:
        void editProperties();
        void applyProperties( const QString & );

    private:
        QAction *d_editAction;
        QWidget *d_widget;
    };


};


#endif // ANALOGWIDGETS_PLUGIN_H
