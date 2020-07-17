// Copyright (C) 2020 Arno Ansems
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

#include "OverheadMap.h"

OverheadMap::OverheadMap() :
    m_originX(0),
    m_originY(0)
{

}

OverheadMap::~OverheadMap()
{

}

void OverheadMap::Draw(IRenderer& renderer, EgaGraph& egaGraph, Level& level)
{
    // TODO: Work in progress !
    level.DrawOverheadMap(renderer, egaGraph);
    RenderableText renderableText(*egaGraph.GetFont(3));
    renderableText.LeftAligned("Overhead map placeholder", EgaBrightWhite, 8, 8);
    renderer.RenderText(renderableText);
}

void OverheadMap::ProcessInput(PlayerInput& playerInput)
{

}