/*
 Copyright (C) 2010-2012 Kristian Duske
 
 This file is part of TrenchBroom.
 
 TrenchBroom is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 TrenchBroom is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with TrenchBroom.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TrenchBroom_EntityTypes_h
#define TrenchBroom_EntityTypes_h

#include <map>
#include <set>
#include <string>
#include <vector>

namespace TrenchBroom {
    namespace Model {
        class Entity;
        
        typedef std::vector<Entity*> EntityList;
        static const EntityList EmptyEntityList;
        
        typedef std::set<Entity*> EntitySet;
        typedef std::pair<EntitySet::iterator, bool> EntitySetInsertResult;
        
        inline EntitySet makeSet(const EntityList& list) {
            EntitySet set;
            set.insert(list.begin(), list.end());
            return set;
        }
        
        inline EntityList makeList(const EntitySet& set) {
            EntityList list;
            EntitySet::const_iterator it, end;
            for (it = set.begin(), end = set.end(); it != end; ++it)
                list.push_back(*it);
            return list;
        }
    }
}

#endif
