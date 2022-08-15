// Copyright (C) 2022 Arno Ansems
// 
// This program is free software: you can redistribute it and/or modify 
// it under the terms of the GNU General Public License as published by 
// the Free Software Foundation, either version 3 of the License, or 
// (at your option) any later version. 
// 
// This program is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
// 
// You should have received a copy of the GNU General Public License 
// along with this program.  If not, see http://www.gnu.org/licenses/ 

//
// ISavedGameConverter
//
// Interface for abstracting conversion of saved games from DOS format to CatacombGL format.
//
#pragma once

#include <stdint.h>
#include <string>
#include <vector>

typedef enum
{
    HeaderItemSignature,
    HeaderItemOldTest,
    HeaderItemPresent,
    HeaderItemName,
    HeaderItemFreezeTime,
    HeaderItemDifficulty,
    HeaderItemMapOn,
    HeaderItemBolts,
    HeaderItemNukes,
    HeaderItemPotions,
    HeaderItemKeys,
    HeaderItemScrolls,
    HeaderItemGems,
    HeaderItemScore,
    HeaderItemBody,
    HeaderItemShotpower,
    HeaderItemEasyModeOn,
    HeaderTtemSkyColor,
    HeaderItemGroundColor,
    HeaderItemMapWidth,
    HeaderItemMapHeight
} HeaderItem;

typedef enum
{
    ObjectActive,
    ObjectTiccount,
    ObjectObclass,
    ObjectState16,
    ObjectState32,
    ObjectShootable,
    ObjectFlags,
    ObjectTileObject,
    ObjectDistance,
    ObjectDir,
    ObjectX,
    ObjectY,
    ObjectTileX,
    ObjectTileY,
    ObjectViewX,
    ObjectViewHeight,
    ObjectAngle,
    ObjectHitpoints,
    ObjectSpeed,
    ObjectSize,
    ObjectXL,
    ObjectXH,
    ObjectYL,
    ObjectYH,
    ObjectTemp1,
    ObjectTemp2,
    ObjectNext,
    ObjectPrev
} ObjectItem;

typedef struct
{
    std::string gameName;
    std::string saveVersion;
    std::vector<HeaderItem> headerItems;
    std::vector<ObjectItem> objectItems;
} DosFormatConfig;

class ISavedGameConverter
{
public:
    virtual ~ISavedGameConverter() {};
    virtual const DosFormatConfig& GetDosFormatConfig() const = 0;
    virtual const uint16_t GetActorId(
        const uint16_t obclass,
        const uint16_t state16,
        const uint32_t state32,
        const int16_t temp1) const = 0;
    virtual const bool IsInertObject(const uint16_t obclass) const = 0;
};
