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

class position_cmd {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.angle_cmd = null;
      this.velocity_cmd = null;
    }
    else {
      if (initObj.hasOwnProperty('angle_cmd')) {
        this.angle_cmd = initObj.angle_cmd
      }
      else {
        this.angle_cmd = new Array(11).fill(0);
      }
      if (initObj.hasOwnProperty('velocity_cmd')) {
        this.velocity_cmd = initObj.velocity_cmd
      }
      else {
        this.velocity_cmd = new Array(11).fill(0);
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type position_cmd
    // Check that the constant length array field [angle_cmd] has the right length
    if (obj.angle_cmd.length !== 11) {
      throw new Error('Unable to serialize array field angle_cmd - length must be 11')
    }
    // Serialize message field [angle_cmd]
    bufferOffset = _arraySerializer.float32(obj.angle_cmd, buffer, bufferOffset, 11);
    // Check that the constant length array field [velocity_cmd] has the right length
    if (obj.velocity_cmd.length !== 11) {
      throw new Error('Unable to serialize array field velocity_cmd - length must be 11')
    }
    // Serialize message field [velocity_cmd]
    bufferOffset = _arraySerializer.float32(obj.velocity_cmd, buffer, bufferOffset, 11);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type position_cmd
    let len;
    let data = new position_cmd(null);
    // Deserialize message field [angle_cmd]
    data.angle_cmd = _arrayDeserializer.float32(buffer, bufferOffset, 11)
    // Deserialize message field [velocity_cmd]
    data.velocity_cmd = _arrayDeserializer.float32(buffer, bufferOffset, 11)
    return data;
  }

  static getMessageSize(object) {
    return 88;
  }

  static datatype() {
    // Returns string type for a message object
    return 'hb_hw_interface/position_cmd';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '3c27cff7b342ce46d7f949fb78b6703f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32[11] angle_cmd #cmd to arduino functions that move the arm.
    float32[11] velocity_cmd ##cmd to arduino functions that move wheels.
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new position_cmd(null);
    if (msg.angle_cmd !== undefined) {
      resolved.angle_cmd = msg.angle_cmd;
    }
    else {
      resolved.angle_cmd = new Array(11).fill(0)
    }

    if (msg.velocity_cmd !== undefined) {
      resolved.velocity_cmd = msg.velocity_cmd;
    }
    else {
      resolved.velocity_cmd = new Array(11).fill(0)
    }

    return resolved;
    }
};

module.exports = position_cmd;
