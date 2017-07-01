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

#include "thermometer.h"
#include "analogwidgets_plugin.h"
#include "defines.h"

using namespace AnalogWidgetPlugin;
    /*------------------------------------------------------------------------------------------------
     *			     			MANOMETER
     *------------------------------------------------------------------------------------------------*/

#ifndef NO_QWT_WIDGETS

ThermoInterface::ThermoInterface( QObject *parent ):
    CustomWidgetInterface( parent )
{
    d_name = "ThermoMeter";
    d_include = "thermometer.h";
    d_icon = QPixmap( ":/pixmaps/qwtthermo.png" );
    d_domXml =
            "<widget class=\"ThermoMeter\" name=\"thermometer\">\n"
                                         " <property name=\"geometry\">\n"
                                         "  <rect>\n"
                                         "   <x>0</x>\n"
                                         "   <y>0</y>\n"
                                         "   <width>40</width>\n"
                                         "   <height>160</height>\n"
                                         "  </rect>\n"
                                         " </property>\n"
                                         " <property name=\"toolTip\" >\n"
                                         "  <string>Shows the pressure</string>\n"
                                         " </property>\n"
                                         " <property name=\"whatsThis\" >\n"
                                         "  <string>The bar meter widget displays "
                                         "the pressure attached to it</string>\n"
                                         " </property>\n"
            "</widget>\n";

        /* "<widget class=\"AnalogWidgetThermo\" name=\"ThermoMeter\">\n"
        " <property name=\"geometry\">\n"
        "  <rect>\n"
        "   <x>0</x>\n"
        "   <y>0</y>\n"
        "   <width>10</width>\n"
        "   <height>100</height>\n"
        "  </rect>\n"
        " </property>\n"
        "</widget>\n"; */
}

QWidget *ThermoInterface::createWidget( QWidget *parent )
{
    return new ThermoMeter( parent );
}

#endif
