/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * Copyright 2011, Blender Foundation.
 */

#include "COM_QualityStepHelper.h"

namespace blender::compositor {

QualityStepHelper::QualityStepHelper()
{
  this->m_quality = eCompositorQuality::High;
  this->m_step = 1;
  this->m_offsetadd = 4;
}

void QualityStepHelper::initExecution(QualityHelper helper)
{
  switch (helper) {
    case COM_QH_INCREASE:
      switch (this->m_quality) {
        case eCompositorQuality::High:
        default:
          this->m_step = 1;
          this->m_offsetadd = 1;
          break;
        case eCompositorQuality::Medium:
          this->m_step = 2;
          this->m_offsetadd = 2;
          break;
        case eCompositorQuality::Low:
          this->m_step = 3;
          this->m_offsetadd = 3;
          break;
      }
      break;
    case COM_QH_MULTIPLY:
      switch (this->m_quality) {
        case eCompositorQuality::High:
        default:
          this->m_step = 1;
          this->m_offsetadd = 4;
          break;
        case eCompositorQuality::Medium:
          this->m_step = 2;
          this->m_offsetadd = 8;
          break;
        case eCompositorQuality::Low:
          this->m_step = 4;
          this->m_offsetadd = 16;
          break;
      }
      break;
  }
}

}  // namespace blender::compositor
