/*
 Copyright (C) 2024 Kristian Duske

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
 along with TrenchBroom. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "Assets/Resource.h"

#include <vector>

namespace TrenchBroom::Assets
{

template <typename TaskRunnerT>
class ResourceManager
{
private:
  std::vector<std::shared_ptr<ResourceBase<TaskRunnerT>>> m_resources;

public:
  const std::vector<std::shared_ptr<ResourceBase<TaskRunnerT>>>& resources() const
  {
    return m_resources;
  }

  template <typename ResourceT>
  void addResource(const std::shared_ptr<Resource<ResourceT, TaskRunnerT>>& resource)
  {
    m_resources.push_back(resource);
  }

  void process(TaskRunnerT& taskRunner)
  {
    for (auto it = m_resources.begin(); it != m_resources.end();)
    {
      auto& resource = *it;
      if (resource.use_count() == 1 && !resource->isDropped())
      {
        resource->drop();
      }

      resource->process(taskRunner);

      it = resource.use_count() == 1 && resource->isDropped() ? m_resources.erase(it)
                                                              : std::next(it);
    }
  }
};

} // namespace TrenchBroom::Assets
