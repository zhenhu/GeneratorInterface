import FWCore.ParameterSet.Config as cms

lhefilter = cms.EDFilter("LHEdecayFilter",
    src = cms.InputTag("externalLHEProducer"),
    NumRequired = cms.int32(4),
    ParticleID = cms.vint32(13)
)                                
