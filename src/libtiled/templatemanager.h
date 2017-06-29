/*
 * templatemanager.h
 * Copyright 2017, Thorbjørn Lindeijer <thorbjorn@lindeijer.nl>
 * Copyright 2017, Mohamed Thabet <thabetx@gmail.com>
 *
 * This file is part of Tiled.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <QObject>

#include "tiled_global.h"
#include "templategroup.h"

namespace Tiled {

class TILEDSHARED_EXPORT TemplateManager : public QObject
{
    Q_OBJECT

public:
    static TemplateManager *instance();

    TemplateGroup *findTemplateGroup(const QString &fileName);
    TemplateGroup *loadTemplateGroup(const QString &fileName, QString *error);

    void setTemplateGroups(TemplateGroups templateGroups);

private:
    Q_DISABLE_COPY(TemplateManager)

    TemplateManager(QObject *parent = nullptr);

    TemplateGroups mTemplateGroups;

    static TemplateManager *mInstance;
};

inline void TemplateManager::setTemplateGroups(TemplateGroups templateGroups)
{ mTemplateGroups = templateGroups; }

} // namespace Tiled::Internal