/*! \file Object factory for dynamicsJRLJapan.
   
  
  Solely provides an implementation of AbstractRobotDynamics.
  Please look at the documentation of AbstrctRobotDynamics 
  for more information.

  Copyright (c) 2009
  @author Olivier Stasse
  
  JRL-Japan, CNRS/AIST
  
  All rights reserved.
  
  Please see License.txt for more informations on the license related to this software.
*/

#ifndef _DYNAMICS_JRL_JAPAN_FACTORY_H_
#define _DYNAMICS_JRL_JAPAN_FACTORY_H_

#if defined (WIN32)
#  ifdef dynamicsJRLJapan_EXPORTS 
#    define DYN_JRL_JAPAN_EXPORT __declspec(dllexport)
#  else  
#    define DYN_JRL_JAPAN_EXPORT __declspec(dllimport)
#  endif 
#else
#  define DYN_JRL_JAPAN_EXPORT
#endif

#include <MatrixAbstractLayer/MatrixAbstractLayer.h>
#include "robotDynamics/jrlHumanoidDynamicRobot.h"

namespace dynamicsJRLJapan
{
  /*! Hooks for to create objects. */

  class DYN_JRL_JAPAN_EXPORT ObjectFactory 
  {
  public:
     CjrlHumanoidDynamicRobot * createhumanoidDynamicRobot();
    
     CjrlDynamicRobot * createDynamicRobot();

     CjrlJoint * createJointFreeflyer(const matrix4d& inInitialPosition);

     CjrlJoint * createJointRotation(const matrix4d& inInitialPosition);
  
     CjrlJoint * createJointTranslation(const matrix4d& inInitialPosition);

     CjrlBody * createBody();
  };

  
  /*! Populate a CjrlHumanoidDynamicRobot instance
    from a OpenHRP vrml file and a file of specificities
    to add semantic information. 
    Right now this will fail it is not a dynamicsJRLJapan instanciated
    object.
    \param OpenHRPVRMFile: Filename which containes the humanoid description
    using OpenHRP format.
    \param MapJointToRankFileName: File describing the joint mapping from
    the VRML ID to the state vector.
    \param FileOfSpecificities: Describe which joints are hands, arm...
    and so on.
    \retval Negative value if failed, 0 otherwise.
  */
  DYN_JRL_JAPAN_EXPORT 
    int parseOpenHRPVRMLFile(CjrlHumanoidDynamicRobot &ajrlHumanoidDynamicRobot,
			     std::string &OpenHRPVRMLFile,
			     std::string &MapJointToRankFileName,
			     std::string &FileOfSpecificities);
  
};
#endif