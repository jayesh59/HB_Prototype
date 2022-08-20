
"use strict";

let GetPlan = require('./GetPlan.js')
let GetNodesInRadius = require('./GetNodesInRadius.js')
let GetNodeData = require('./GetNodeData.js')
let GetMap2 = require('./GetMap2.js')
let SetGoal = require('./SetGoal.js')
let LoadDatabase = require('./LoadDatabase.js')
let AddLink = require('./AddLink.js')
let PublishMap = require('./PublishMap.js')
let ResetPose = require('./ResetPose.js')
let DetectMoreLoopClosures = require('./DetectMoreLoopClosures.js')
let CleanupLocalGrids = require('./CleanupLocalGrids.js')
let GetMap = require('./GetMap.js')
let ListLabels = require('./ListLabels.js')
let GlobalBundleAdjustment = require('./GlobalBundleAdjustment.js')
let RemoveLabel = require('./RemoveLabel.js')
let SetLabel = require('./SetLabel.js')

module.exports = {
  GetPlan: GetPlan,
  GetNodesInRadius: GetNodesInRadius,
  GetNodeData: GetNodeData,
  GetMap2: GetMap2,
  SetGoal: SetGoal,
  LoadDatabase: LoadDatabase,
  AddLink: AddLink,
  PublishMap: PublishMap,
  ResetPose: ResetPose,
  DetectMoreLoopClosures: DetectMoreLoopClosures,
  CleanupLocalGrids: CleanupLocalGrids,
  GetMap: GetMap,
  ListLabels: ListLabels,
  GlobalBundleAdjustment: GlobalBundleAdjustment,
  RemoveLabel: RemoveLabel,
  SetLabel: SetLabel,
};
