/*
 * qr_agent.h
 *
 *  Created on: Dec 21, 2017
 *      Author: bibei
 */

#ifndef INCLUDE_AGENT_QR_AGENT_H_
#define INCLUDE_AGENT_QR_AGENT_H_

#include <rl_agent_base/rl_agent/robot_plugin.h>
#include <controller_interface/controller.h>

class QrAgent : public rl_agent::RobotPlugin {
public:
  QrAgent();
  virtual ~QrAgent();
};

#endif /* INCLUDE_AGENT_QR_AGENT_H_ */
