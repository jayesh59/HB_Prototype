#ifndef _ROS_hb_hw_interface_state_update_h
#define _ROS_hb_hw_interface_state_update_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hb_hw_interface
{

  class state_update : public ros::Msg
  {
    public:
      float c_angles[11];
      float c_velocities[11];

    state_update():
      c_angles(),
      c_velocities()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 11; i++){
      union {
        float real;
        uint32_t base;
      } u_c_anglesi;
      u_c_anglesi.real = this->c_angles[i];
      *(outbuffer + offset + 0) = (u_c_anglesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_c_anglesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_c_anglesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_c_anglesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->c_angles[i]);
      }
      for( uint32_t i = 0; i < 11; i++){
      union {
        float real;
        uint32_t base;
      } u_c_velocitiesi;
      u_c_velocitiesi.real = this->c_velocities[i];
      *(outbuffer + offset + 0) = (u_c_velocitiesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_c_velocitiesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_c_velocitiesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_c_velocitiesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->c_velocities[i]);
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
      } u_c_anglesi;
      u_c_anglesi.base = 0;
      u_c_anglesi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_c_anglesi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_c_anglesi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_c_anglesi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->c_angles[i] = u_c_anglesi.real;
      offset += sizeof(this->c_angles[i]);
      }
      for( uint32_t i = 0; i < 11; i++){
      union {
        float real;
        uint32_t base;
      } u_c_velocitiesi;
      u_c_velocitiesi.base = 0;
      u_c_velocitiesi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_c_velocitiesi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_c_velocitiesi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_c_velocitiesi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->c_velocities[i] = u_c_velocitiesi.real;
      offset += sizeof(this->c_velocities[i]);
      }
     return offset;
    }

    virtual const char * getType() override { return "hb_hw_interface/state_update"; };
    virtual const char * getMD5() override { return "ef499ec12d5d495e7c8a49b8fded425f"; };

  };

}
#endif
