#ifndef _ROS_hb_hw_interface_position_cmd_h
#define _ROS_hb_hw_interface_position_cmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hb_hw_interface
{

  class position_cmd : public ros::Msg
  {
    public:
      float angle_cmd[11];
      float velocity_cmd[11];

    position_cmd():
      angle_cmd(),
      velocity_cmd()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 11; i++){
      union {
        float real;
        uint32_t base;
      } u_angle_cmdi;
      u_angle_cmdi.real = this->angle_cmd[i];
      *(outbuffer + offset + 0) = (u_angle_cmdi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle_cmdi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle_cmdi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle_cmdi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle_cmd[i]);
      }
      for( uint32_t i = 0; i < 11; i++){
      union {
        float real;
        uint32_t base;
      } u_velocity_cmdi;
      u_velocity_cmdi.real = this->velocity_cmd[i];
      *(outbuffer + offset + 0) = (u_velocity_cmdi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity_cmdi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity_cmdi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity_cmdi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_cmd[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 11; i++){
      union {
        float real;
        uint32_t base;
      } u_angle_cmdi;
      u_angle_cmdi.base = 0;
      u_angle_cmdi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle_cmdi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle_cmdi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle_cmdi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle_cmd[i] = u_angle_cmdi.real;
      offset += sizeof(this->angle_cmd[i]);
      }
      for( uint32_t i = 0; i < 11; i++){
      union {
        float real;
        uint32_t base;
      } u_velocity_cmdi;
      u_velocity_cmdi.base = 0;
      u_velocity_cmdi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity_cmdi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity_cmdi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity_cmdi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity_cmd[i] = u_velocity_cmdi.real;
      offset += sizeof(this->velocity_cmd[i]);
      }
     return offset;
    }

    virtual const char * getType() override { return "hb_hw_interface/position_cmd"; };
    virtual const char * getMD5() override { return "3c27cff7b342ce46d7f949fb78b6703f"; };

  };

}
#endif
