/*
 * QEstEidCommon
 *
 * Copyright (C) 2010 Jargo Kõster <jargo@innovaatik.ee>
 * Copyright (C) 2010 Raul Metsma <raul@innovaatik.ee>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#include "AboutWidget.h"

#include "ui_AboutWidget.h"

#include <QApplication>

class AboutWidgetPrivate: public Ui::AboutWidget
{};

AboutWidget::AboutWidget(QWidget *parent)
:	QWidget(parent)
,	d( new AboutWidgetPrivate )
{
	d->setupUi( this );
	setAttribute( Qt::WA_DeleteOnClose, true );
	setWindowFlags( Qt::Sheet );
	d->content->setText( QString("%1\n%2").arg( qApp->applicationName(), qApp->applicationVersion() ) );
}

AboutWidget::~AboutWidget() { delete d; }