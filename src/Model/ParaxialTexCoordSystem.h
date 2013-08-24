/*
 Copyright (C) 2010-2013 Kristian Duske
 
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

#ifndef __TrenchBroom__ParaxialTexCoordSystem__
#define __TrenchBroom__ParaxialTexCoordSystem__

#include "TrenchBroom.h"
#include "VecMath.h"

namespace TrenchBroom {
    namespace Model {
        class ParaxialTexCoordSystem {
        private:
            static const Vec3 BaseAxes[];
            
            Vec3 m_xAxis;
            Vec3 m_yAxis;
        public:
            ParaxialTexCoordSystem(const Vec3& point0, const Vec3& point1, const Vec3& point2);

            void update(const Vec3& normal, const float rotation);
            const Vec3& xAxis() const;
            const Vec3& yAxis() const;

            static void axesAndIndices(const Vec3& normal, Vec3& xAxis, Vec3& yAxis, size_t& planeNormIndex, size_t& faceNormIndex);
            static void rotateAxes(Vec3& xAxis, Vec3& yAxis, const FloatType angle, const size_t planeNormIndex);
        };
    }
}

#endif /* defined(__TrenchBroom__QuakeTexCoordPolicy__) */
