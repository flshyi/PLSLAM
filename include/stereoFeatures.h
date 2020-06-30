/*****************************************************************************
**      Stereo VO and SLAM by combining point and line segment features     **
******************************************************************************
**                                                                          **
**  Copyright(c) 2016-2018, Ruben Gomez-Ojeda, University of Malaga         **
**  Copyright(c) 2016-2018, David Zuñiga-Noël, University of Malaga         **
**  Copyright(c) 2016-2018, MAPIR group, University of Malaga               **
**                                                                          **
**  This program is free software: you can redistribute it and/or modify    **
**  it under the terms of the GNU General Public License (version 3) as     **
**  published by the Free Software Foundation.                              **
**                                                                          **
**  This program is distributed in the hope that it will be useful, but     **
**  WITHOUT ANY WARRANTY; without even the implied warranty of              **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the            **
**  GNU General Public License for more details.                            **
**                                                                          **
**  You should have received a copy of the GNU General Public License       **
**  along with this program.  If not, see <http://www.gnu.org/licenses/>.   **
**                                                                          **
*****************************************************************************/

#pragma once
#include <eigen3/Eigen/Core>
#include <config.h>
using namespace Eigen;

namespace StVO{

class PointFeature
{

public:

    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;

    PointFeature( Vector3d P_, Vector2d pl_obs_);
    PointFeature( Vector2d pl_, double disp_, Vector3d P_ );
    PointFeature( Vector2d pl_, double disp_, Vector3d P_, int idx_ );
    PointFeature( Vector2d pl_, double disp_, Vector3d P_, int idx_, int level );
    PointFeature( Vector2d pl_, double disp_, Vector3d P_, int idx_, int level, Matrix3d covP_an_ );
    PointFeature( Vector2d pl_, double disp_, Vector3d P_, Vector2d pl_obs_ );
    PointFeature( Vector2d pl_, double disp_, Vector3d P_, Vector2d pl_obs_,
                  int idx_, int level_, double sigma2_, Matrix3d covP_an_, bool inlier_ );
    ~PointFeature(){};

    PointFeature* safeCopy();

    int idx;
    Vector2d pl, pl_obs;
    double   disp;
    Vector3d P;
    bool inlier;
    int level;
    double sigma2 = 1.0;
    Matrix3d covP_an;

};

class LineFeature
{

public:

    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;

    LineFeature( Vector3d sP_, Vector3d eP_, Vector3d le_obs_);

    LineFeature( Vector3d sP_, Vector3d eP_, Vector3d le_obs_, Vector2d spl_obs_, Vector2d epl_obs_);

    LineFeature( Vector2d spl_, double sdisp_, Vector3d sP_,
                 Vector2d epl_, double edisp_, Vector3d eP_,
                 Vector3d le_,  int idx_);

    LineFeature( Vector2d spl_, double sdisp_, Vector3d sP_,
                 Vector2d epl_, double edisp_, Vector3d eP_,
                 Vector3d le_,  double angle_, int idx_);

    LineFeature( Vector2d spl_, double sdisp_, Vector3d sP_,
                 Vector2d epl_, double edisp_, Vector3d eP_,
                 Vector3d le_,  double angle_, int idx_, int level);

    /*LineFeature( Vector2d spl_, double sdisp_, Vector3d sP_,
                 Vector2d epl_, double edisp_, Vector3d eP_,
                 Vector3d le_,  double angle_, int idx_, int level, Matrix3d covS_an_, Matrix3d covE_an_);*/

    LineFeature( Vector2d spl_, double sdisp_, Vector3d sP_,
                 Vector2d epl_, double edisp_, Vector3d eP_, Vector3d le_);

    LineFeature( Vector2d spl_, double sdisp_, Vector3d sP_,
                 Vector2d epl_, double edisp_, Vector3d eP_,
                 Vector3d le_, Vector3d le_obs_);

    /*LineFeature( Vector2d spl_, double sdisp_, Vector3d sP_,
                 Vector2d epl_, double edisp_, Vector3d eP_,
                 Vector3d le_,  double angle_, int idx_, int level, Vector2d spr_, Vector2d epr_);*/

    LineFeature( Vector2d spl_, double sdisp_, Vector3d sP_, Vector2d spl_obs_, double sdisp_obs_,
                 Vector2d epl_, double edisp_, Vector3d eP_, Vector2d epl_obs_, double edisp_obs_,
                 Vector3d le_, Vector3d le_obs_, double angle_, int idx_, int level_, bool inlier_, double sigma2_,
                 Matrix3d covE_an_, Matrix3d covS_an_);

    ~LineFeature(){};

    LineFeature* safeCopy();

    int idx;
    Vector2d spl,epl, spl_obs, epl_obs;
    double   sdisp, edisp, angle, sdisp_obs, edisp_obs;
    Vector3d sP,eP;
    Vector3d le, le_obs;
    bool inlier;

    int level;
    double sigma2 = 1.0;

    Matrix3d covE_an, covS_an;



};

}
