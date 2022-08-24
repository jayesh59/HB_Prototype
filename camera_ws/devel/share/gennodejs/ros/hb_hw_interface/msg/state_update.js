// Auto-generated. Do not edit!

// (in-package hb_hw_interface.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class state_update {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.c_angles = null;
      this.c_velocities = null;
    }
    else {
      if (initObj.hasOwnProperty('c_angles')) {
        this.c_angles = initObj.c_angles
      }
      else {
        this.c_angles = new Array(11).fill(0);
      }
      if (initObj.hasOwnProperty('c_velocities')) {
        this.c_velocities = initObj.c_velocities
      }
      else {
        this.c_velocities = new Array(11).fill(0);
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type state_update
    // Check that the constant length array field [c_angles] has the right length
    if (obj.c_angles.length !== 11) {
      throw new Error('Unable to serialize array field c_angles - length must be 11')
    }
    // Serialize message field [c_angles]
    bufferOffset = _arraySerializer.float32(obj.c_angles, buffer, bufferOffset, 11);
    // Check that the constant length array field [c_velocities] has the right length
    if (obj.c_velocities.length !== 11) {
      throw new Error('Unable to serialize array field c_velocities - length must be 11')
    }
    // Serialize message field [c_velocities]
    bufferOffset = _arraySerializer.float32(obj.c_velocities, buffer, bufferOffset, 11);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type state_update
    let len;
    let data = new state_update(null);
    // Deserialize message field [c_angles]
    data.c_angles = _arrayDeserializer.float32(buffer, bufferOffset, 11)
    // Deserialize message field [c_velocities]
    data.c_velocities = _arrayDeserializer.float32(buffer, bufferOffset, 11)
    return data;
  }

  static getMessageSize(object) {
    return 88;
  }

  static datatype() {
    // Returns string type for a message object
    return 'hb_hw_interface/state_update';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ef499ec12d5d495e7c8a49b8fded425f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32[11] c_angles #current angle values as output as a result of change in posture due to cmd from ROS.
    float32[11] c_velocities #current velocity values as output as a result of change in velocity of wheels due to cmd from ROS.
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new state_update(null);
    if (msg.c_angles !== undefined) {
      resolved.c_angles = msg.c_angles;
    }
    else {
      resolved.c_angles = new Array(11).fill(0)
    }

    if (msg.c_velocities !== undefined) {
      resolved.c_velocities = msg.c_velocities;
    }
    else {
      resolved.c_velocities = new Array(11).fill(0)
    }

    return resolved;
    }
};

module.exports = state_update;
