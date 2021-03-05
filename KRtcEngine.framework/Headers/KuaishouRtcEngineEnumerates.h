#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, KuaishouRtcErrorCode) {
  KuaishouRtcErrorCodeNoError = 0,

  /* same with notify type */
  KuaishouRtcErrorCodeSignalJoinedRoomConnectedInvalid = 19,
  KuaishouRtcErrorCodeDisconnectedFromMediaServer = 22,
  KuaishouRtcErrorCodeJoinChannelFailed = 50,
  KuaishouRtcErrorCodeVideoEncoderFatalError = 53,
  KuaishouRtcErrorCodeVideoDecoderFatalError = 54,

  KuaishouRtcErrorCodeServerRejectWithRoomNotFound = 85,

  /* inner error */
  KuaishouRtcErrorCodeAudioDevice = 0x00010001,
  KuaishouRtcErrorCodeParamInvalid = 0x00010002,
  KuaishouRtcErrorCodeLeaveChannel = 0x00010003,
};

typedef NS_ENUM(NSInteger, KuaishouRtcWarningCode) {
  /* same with notify type */
  KuaishouRtcWarnCodeNoWarn = 0,
  KuaishouRtcWarnCodeNetworkNotGood = 5,
  KuaishouRtcWarnCodeKtpReconnectTooManyTimes = 17,
  KuaishouRtcWarnCodeDisconnectedFromMediaServer = 22,

  KuaishouRtcWarnCodeSignalingHeartbeatTimeout = 200,
};

typedef NS_OPTIONS(NSUInteger, KuaishouRtcEngineQosEnableFlag) {
  KuaishouRtcEngineQosDisableAll = 0x0,
  KuaishouRtcEngineQosEnableRealTime  = 0x00000001,
  KuaishouRtcEngineQosEnableSummary   = 0x00000002,
  KuaishouRtcEngineQosEnableNetworkInfo = 0x00000004,
};

typedef NS_ENUM(NSUInteger, KuaishouRtcEngineReverbLevel) {
  KuaishouRtcEngineReverbNone = 0,
  KuaishouRtcEngineReverbChorus = 1,
  KuaishouRtcEngineReverbClassic = 2,
  KuaishouRtcEngineReverbPop = 3,
  KuaishouRtcEngineReverbHeavy = 4,
  KuaishouRtcEngineReverbReverb = 5,
  KuaishouRtcEngineReverbKTV = 6,
  KuaishouRtcEngineReverbBathRoom = 7,
  KuaishouRtcEngineReverbRecord  = 8,
  KuaishouRtcEngineReverbStudio  = 9,
  KuaishouRtcEngineReverbStage = 10,
  KuaishouRtcEngineReverbConcert = 11,
  KuaishouRtcEngineReverbLight = 12,
  KuaishouRtcEngineReverbSuperStar = 13,
  KuaishouRtcEngineReverbAmazing = 14,
  KuaishouRtcEngineReverbAmazing2 = 15,
  KuaishouRtcEngineReverbOldTimeRadio = 16
};

typedef NS_ENUM(NSUInteger, KuaishouRtcEngineVoiceEffectOption) {
  KuaishouRtcEngineVeoNone = 0,
  KuaishouRtcEngineVeoEcho = 1,
  KuaishouRtcEngineVeoThriller = 2,
  KuaishouRtcEngineVeoRobot = 3,
  KuaishouRtcEngineVeoLorie = 4,
  KuaishouRtcEngineVeoUncle = 5,
  KuaishouRtcEngineVeoDieFat = 6,
  KuaishouRtcEngineVeoBadBoy = 7,
  KuaishouRtcEngineVeoXiaoHuangRen = 8,
  KuaishouRtcEngineVeoHeavyMetal = 9,
  KuaishouRtcEngineVeoDenon = 10,
  KuaishouRtcEngineVeoHeavyMechinery = 11,
  KuaishouRtcEngineVeoPowerCurrent = 12,
  KuaishouRtcEngineVeoCute = 13,
};

typedef NS_ENUM(NSUInteger, KuaishouRtcEngineBitmapColorSpace) {
  KuaishouRtcEngineBitmapRGBA,
  KuaishouRtcEngineBitmapARGB,
  KuaishouRtcEngineBitmapBGRA,
  KuaishouRtcEngineBitmapABGR
};

typedef NS_OPTIONS(NSUInteger, KuaishouRtcEngineMediaDelegateFlags) {
  KuaishouRtcEngineMediaDelegateDisableAll = 0x0,
  KuaishouRtcEngineMediaDelegateVideoPreEncode  = 0x00000001,
  KuaishouRtcEngineMediaDelegateVideoEncoded    = 0x00000002,
  KuaishouRtcEngineMediaDelegateVideoPreDecode  = 0x00000004,
  KuaishouRtcEngineMediaDelegateVideoDecoded    = 0x00000008,
  KuaishouRtcEngineMediaDelegateAudioPreEncode  = 0x00000100,
  KuaishouRtcEngineMediaDelegateAudioEncoded    = 0x00000200,
  KuaishouRtcEngineMediaDelegateAudioPreDecode  = 0x00000400,
  KuaishouRtcEngineMediaDelegateAudioDecoded    = 0x00000800,
  KuaishouRtcEngineMediaDelegateEnableAll       = 0xFFFFFFFF,
};

typedef NS_ENUM(NSUInteger, KuaishouRtcEngineHowlingSuppressionMode) {
  KuaishouRtcEngineHsNoProcess = 0,
  KuaishouRtcEngineHsDetectOnly,
  KuaishouRtcEngineHsSupression,
  KuaishouRtcEngineHsMaxMode
};

typedef NS_ENUM(NSUInteger, KuaishouRtcEngineMicMuteType) {
  KuaishouRtcEngineMicUnMute = 0,
  KuaishouRtcEngineMicMute,
  KuaishouRtcEngineMicMuteAndFillComfortableNoise,
};

typedef NS_OPTIONS(NSUInteger, KuaishouRtcEngineAudioBypassDataOptions) {
  KuaishouRtcEngineAudioBypassDataWithAEC = 0x00000001,
};

typedef NS_ENUM(NSUInteger, KuaishouRtcEngineNetworkType) {
  KuaishouRtcEngineNetworkTypeUnknown = 0,
  KuaishouRtcEngineNetworkTypeTelephone,
  KuaishouRtcEngineNetworkTypeWifi
};

typedef NS_ENUM(NSUInteger, KuaishouRtcEngineAgcMode) {
  KuaishouRtcEngineAgcDefault = 0,
  KuaishouRtcEngineAgcEnable = 1,
  KuaishouRtcEngineAgcDisable = 2
};

typedef NS_ENUM(NSUInteger, KuaishouRtcEngineVideoReqMode) {
  KuaishouRtcEngineVideoReqMode1PlusN = 1,
  KuaishouRtcEngineVideoReqModeMxN = 2,
  KuaishouRtcEngineVideoReqMode1PlusNForDynRes = 3
};

typedef NS_ENUM(NSInteger, KuaishouRtcEngineAudioOutputRouting) {
  KuaishouRtcEngineAudioRouterUnknown = -1,
  KuaishouRtcEngineAudioRouterHeadset = 0,
  KuaishouRtcEngineAudioRouterEarpiece = 1,
  KuaishouRtcEngineAudioRouterHeadsetNoMic = 2,
  KuaishouRtcEngineAudioRouterSpeakerphone = 3,
  KuaishouRtcEngineAudioRouterLoudspeaker = 4,
  KuaishouRtcEngineAudioRouterHeadsetBluetooth = 5,
  KuaishouRtcEngineAudioRouterUsb = 6,
  KuaishouRtcEngineAudioRouterHdmi = 7,
  KuaishouRtcEngineAudioRouterDisplayPort = 8,
  KuaishouRtcEngineAudioRouterAirplay = 9,
};

/** Video mirror mode. */
typedef NS_ENUM(NSUInteger, KuaishouRtcEngineVideoMirrorMode) {
  KuaishouRtcEngineVideoMirrorModeEnabled = 1,
  KuaishouRtcEngineVideoMirrorModeDisabled = 2,
};

typedef NS_ENUM(NSUInteger, KuaishouRtcEngineVideoRenderMode) {
  KuaishouRtcEngineVideoRenderModeFitWithCropping = 0,
  KuaishouRtcEngineVideoRenderModeScaleToFit = 1
};

typedef NS_ENUM(NSInteger, KuaishouRtcEngineBgmError) {
  KuaishouRtcEngineBgmNoError = 0,
  KuaishouRtcEngineBgmErrorUnknown,
  KuaishouRtcEngineBgmErrorNotSupported,
  KuaishouRtcEngineBgmErrorIo,
  KuaishouRtcEngineBgmErrorMalformed,
};

typedef NS_ENUM(NSInteger, KuaishouRtcAudioRecordingStateCode) {
  KuaishouRtcAudioRecordingStateRecording,
  KuaishouRtcAudioRecordingStatePaused,
  KuaishouRtcAudioRecordingStateStoppped,
  KuaishouRtcAudioRecordingStateFailed,
};

typedef NS_ENUM(NSInteger, KuaishouRtcAudioRecordingErrorCode) {
  KuaishouRtcAudioRecordingErrorCanNotOpen,
  KuaishouRtcAudioRecordingErrorTooFrequentCall,
  KuaishouRtcAudioRecordingErrorInterruptedEOF,
  KuaishouRtcAudioRecordingErrorOK,
};


typedef NS_ENUM(NSUInteger, KuaishouRtcEngineDestChannel) {
  KuaishouRtcEngineDestChannelNone = 0,
  KuaishouRtcEngineDestChannelLive = 1,
  KuaishouRtcEngineDestChannelRTC = 2,
  KuaishouRtcEngineDestChannelAll = 3,
};

typedef NS_ENUM(NSUInteger, KuaishouRtcRemoteVideoStreamType) {
  KuaishouRtcRemoteVideoStreamTypeHigh = 0,
  KuaishouRtcRemoteVideoStreamTypeLow,
};

/** The state of the remote video. */
typedef NS_ENUM(NSUInteger, KuaishouRtcEngineRemoteVideoState) {
  KuaishouRtcEngineRemoteVideoStateStopped = 0,
  KuaishouRtcEngineRemoteVideoStateStarting = 1,
  KuaishouRtcEngineRemoteVideoStateDecoding = 2,
  KuaishouRtcEngineRemoteVideoStateFrozen = 3,
  KuaishouRtcEngineRemoteVideoStateFailed = 4,
};

/** The reason of the remote video state change. */
typedef NS_ENUM(NSUInteger, KuaishouRtcEngineRemoteVideoStateReason) {
  /** 0: Internal reasons. */
  KuaishouRtcEngineRemoteVideoStateReasonInternal = 0,
  /** 1: Network congestion. */
  KuaishouRtcEngineRemoteVideoStateReasonNetworkCongestion = 1,
  /** 2: Network recovery. */
  KuaishouRtcEngineRemoteVideoStateReasonNetworkRecovery = 2,
  /** 3: The local user stops receiving the remote video stream or disables the video module. */
  KuaishouRtcEngineRemoteVideoStateReasonLocalMuted = 3,
  /** 4: The local user resumes receiving the remote video stream or enables the video module. */
  KuaishouRtcEngineRemoteVideoStateReasonLocalUnmuted = 4,
  /** 5: The remote user stops sending the video stream or disables the video module. */
  KuaishouRtcEngineRemoteVideoStateReasonRemoteMuted = 5,
  /** 6: The remote user resumes sending the video stream or enables the video module. */
  KuaishouRtcEngineRemoteVideoStateReasonRemoteUnmuted = 6,
  /** 7: The remote user leaves the channel. */
  KuaishouRtcEngineRemoteVideoStateReasonRemoteOffline = 7,
  /** 8: The remote media stream falls back to the audio-only stream due to poor network conditions. */
  KuaishouRtcEngineRemoteVideoStateReasonAudioFallback = 8,
  /** 9: The remote media stream switches back to the video stream after the network conditions improve. */
  KuaishouRtcEngineRemoteVideoStateReasonAudioFallbackRecovery = 9,
};

typedef NS_ENUM(NSUInteger, KuaishouRtcEngineLogLevel) {
  KuaishouRtcEngineLogLevelDebug = 0,
  KuaishouRtcEngineLogLevelInfo,
  KuaishouRtcEngineLogLevelWarn,
  KuaishouRtcEngineLogLevelError,
  KuaishouRtcEngineLogLevelNone,
};

// The state of the audio mixing file
typedef NS_ENUM(NSInteger, KuaishouRtcEngineAudioMixingStateCode) {
  KuaishouRtcEngineAudioMixingStatePlaying = 0,
  KuaishouRtcEngineAudioMixingStatePaused = 1,
  KuaishouRtcEngineAudioMixingStateStopped = 2,
  KuaishouRtcEngineAudioMixingStateFailed = 3,
};

// The error code of the audio mixing file
typedef NS_ENUM(NSInteger, KuaishouRtcEngineAudioMixingErrorCode) {
  KuaishouRtcEngineAudioMixingErrorOK = 0,
  KuaishouRtcEngineAudioMixingUnknown,
  KuaishouRtcEngineAudioMixingNotSupported,
  KuaishouRtcEngineAudioMixingIo,
  KuaishouRtcEngineAudioMixingMalformed,
};

typedef NS_ENUM(NSUInteger, KuaishouRtcEngineVideoFrameType) {
  KuaishouRtcEngineVideoFrameTypeI = 0,
  KuaishouRtcEngineVideoFrameTypeP,
  KuaishouRtcEngineVideoFrameTypeBRef,
  KuaishouRtcEngineVideoFrameTypeB,
};

typedef NS_ENUM(NSUInteger, KuaishouRtcEngineVideoMixType) {
  KuaishouRtcEngineVideoMixTypeUnknown = 0,
  KuaishouRtcEngineVideoMixTypeSingle,
  KuaishouRtcEngineVideoMixTypeOverlay,
  KuaishouRtcEngineVideoMixTypeSideBySide,
  KuaishouRtcEngineVideoMixTypeExternalSource,
};

typedef NS_ENUM(NSUInteger, KuaishouRtcEngineVideoColorSpace) {
  KuaishouRtcEngineBT601LimitCsp = 0,
  KuaishouRtcEngineBT601FullCsp,
  KuaishouRtcEngineBT709LimitCsp,
  KuaishouRtcEngineBT709FullCsp
};

typedef NS_ENUM(NSUInteger, KuaishouRtcEngineMediaMode) {
  KuaishouRtcEngineMediaModeAudioOnly = 0,
  KuaishouRtcEngineMediaModeVideoOnly,
  KuaishouRtcEngineMediaModeAudioAndVideo,
};

/** State of importing an external video stream in a live broadcast. */
// should same with UrlEventDetail
typedef NS_ENUM(NSUInteger, KuaishouRtcEngineFileStreamStatus) {
  KuaishouRtcEngineFileStreamStatusNormal = 0,
  KuaishouRtcEngineFileStreamStatusStopAbnormal = 1,
  KuaishouRtcEngineFileStreamStatusStartAbnormal = 0x00010000,
  KuaishouRtcEngineFileStreamStatusReadFrame = 0x00010001,
};

typedef NS_ENUM(NSUInteger, KuaishouRtcEngineBroadcastType) {
  KuaishouRtcEngineBroadcastTypePassThrough,    // ID 0 for pass through transmission
  KuaishouRtcEngineBroadcastTypeGuestAudioInfo, // guest send audio info to anchor
  KuaishouRtcEngineBroadcastTypePeerMuteStatus, // broadcast mute status to peer
};

/** The state of the local audio. */
typedef NS_ENUM(NSUInteger, KuaishouRtcEngineLocalAudioState) {
  KuaishouRtcEngineLocalAudioStateStopped = 0,
  KuaishouRtcEngineLocalAudioStateRecording = 1,
  KuaishouRtcEngineLocalAudioStateEncoding = 2,
  KuaishouRtcEngineLocalAudioStateFailed = 3,
};

/** The error information of the local audio. */
typedef NS_ENUM(NSUInteger, KuaishouRtcEngineLocalAudioError) {
  KuaishouRtcEngineLocalAudioErrorOk = 0,
  KuaishouRtcEngineLocalAudioErrorFailure = 1,
  KuaishouRtcEngineLocalAudioErrorDeviceNoPermission = 2,
  KuaishouRtcEngineLocalAudioErrorDeviceBusy = 3,
  KuaishouRtcEngineLocalAudioErrorRecordFailure = 4,
  KuaishouRtcEngineLocalAudioErrorEncodeFailure = 5,
};

/** The state of the remote audio. */
typedef NS_ENUM(NSUInteger, KuaishouRtcEngineRemoteAudioState) {
  KuaishouRtcEngineRemoteAudioStateStopped = 0,
  KuaishouRtcEngineRemoteAudioStateStarting = 1,
  KuaishouRtcEngineRemoteAudioStateDecoding = 2,
  KuaishouRtcEngineRemoteAudioStateFrozen = 3,
  KuaishouRtcEngineRemoteAudioStateFailed = 4,
};

/** The reason of the remote audio state change. */
typedef NS_ENUM(NSUInteger, KuaishouRtcEngineRemoteAudioStateReason) {
  KuaishouRtcEngineRemoteAudioReasonInternal = 0,
  KuaishouRtcEngineRemoteAudioReasonNetworkCongestion = 1,
  KuaishouRtcEngineRemoteAudioReasonNetworkRecovery = 2,
  KuaishouRtcEngineRemoteAudioReasonLocalMuted = 3,
  KuaishouRtcEngineRemoteAudioReasonLocalUnmuted = 4,
  KuaishouRtcEngineRemoteAudioReasonRemoteMuted = 5,
  KuaishouRtcEngineRemoteAudioReasonRemoteUnmuted = 6,
  KuaishouRtcEngineRemoteAudioReasonRemoteOffline = 7,
};

/** The state of the local video stream. */
typedef NS_ENUM(NSInteger, KuaishouRtcEngineLocalVideoStreamState) {
  KuaishouRtcEngineLocalVideoStreamStateStopped = 0,
  KuaishouRtcEngineLocalVideoStreamStateCapturing = 1,
  KuaishouRtcEngineLocalVideoStreamStateEncoding = 2,
  KuaishouRtcEngineLocalVideoStreamStateFailed = 3,
};

/** The detailed error information of the local video. */
typedef NS_ENUM(NSInteger, KuaishouRtcEngineLocalVideoStreamError) {
  KuaishouRtcEngineLocalVideoStreamErrorOK = 0,
  KuaishouRtcEngineLocalVideoStreamErrorFailure = 1,
  KuaishouRtcEngineLocalVideoStreamErrorDeviceNoPermission = 2,
  KuaishouRtcEngineLocalVideoStreamErrorDeviceBusy = 3,
  KuaishouRtcEngineLocalVideoStreamErrorCaptureFailure = 4,
  KuaishouRtcEngineLocalVideoStreamErrorEncodeFailure = 5,
};

typedef NS_ENUM(NSUInteger, KuaishouRtcEngineNotificationType) {
  KuaishouRtcEngineNotificationTypeSignalingParticipantUpdate = 0,
  KuaishouRtcEngineNotificationTypeSignalingServerNodeChanged = 1,
  KuaishouRtcEngineNotificationTypeCallModeChangedToLiveStream = 2,
  KuaishouRtcEngineNotificationTypeCallModeChangedToRtc = 3,
  // KuaishouRtcEngineNotificationTypeCallInfoVideoTxBlackScreen = 4, // deprecated
  KuaishouRtcEngineNotificationTypeNetworkNotGood = 5,
  KuaishouRtcEngineNotificationTypeVideoFramesDroppedBefEnc = 6,
  KuaishouRtcEngineNotificationTypeLivePkStart = 7,
  KuaishouRtcEngineNotificationTypeLivePkStop = 8,
  KuaishouRtcEngineNotificationTypeActiveSpeakerChanged = 9,
  KuaishouRtcEngineNotificationTypeLiveChatStartVideo = 10,
  KuaishouRtcEngineNotificationTypeLiveChatStartAudio = 11,
  KuaishouRtcEngineNotificationTypeLiveChatStop = 12,
  KuaishouRtcEngineNotificationTypeVoicePartyStart = 13,
  KuaishouRtcEngineNotificationTypeVoicePartyStop = 14,
  // KuaishouRtcEngineNotificationTypeHighQualityChatStart = 15, // deprecated
  // KuaishouRtcEngineNotificationTypeHighQualityChatStop = 16, // deprecated
  KuaishouRtcEngineNotificationTypeKtpReconnectTooManyTimes = 17,
  KuaishouRtcEngineNotificationTypeAudioJitterBufferEmpty = 18,
  KuaishouRtcEngineNotificationTypeSignalJoinedRoomConnectedInvalid = 19,
  KuaishouRtcEngineNotificationTypeParticipantUpdate = 20,
  KuaishouRtcEngineNotificationTypeLiveStreamWithDelayStopped = 21,
  KuaishouRtcEngineNotificationTypeDisconnectedFromMediaServer = 22,
  KuaishouRtcEngineNotificationTypeFatalError = 23,
  KuaishouRtcEngineNotificationTypeLiveStreamStopped = 24,
  KuaishouRtcEngineNotificationTypeLowLatencyLiveStart = 25,
  KuaishouRtcEngineNotificationTypeLowLatencyLiveStop = 26,
  KuaishouRtcEngineNotificationTypeScreencastStopped = 27,
  KuaishouRtcEngineNotificationTypeSessionStart = 28,
  KuaishouRtcEngineNotificationTypeSessionStop = 29,
  KuaishouRtcEngineNotificationTypeParticipantAdd = 30,
  KuaishouRtcEngineNotificationTypeParticipantRemove = 31,
  KuaishouRtcEngineNotificationTypeTalkInMuteIndication = 32,
  KuaishouRtcEngineNotificationTypeMuteMicByOther = 33,
  KuaishouRtcEngineNotificationTypeUnmuteMicByOther = 34,
  KuaishouRtcEngineNotificationTypeHowlingDetected = 35,
  KuaishouRtcEngineNotificationTypeRoomConfigUpdated = 36,
  KuaishouRtcEngineNotificationTypeGetRoomConfig = 37,
  KuaishouRtcEngineNotificationTypeAudioPassThroughMsgNotify = 38,
  KuaishouRtcEngineNotificationTypeVoiceCommentNotify = 39,
  KuaishouRtcEngineNotificationTypeRtcStats = 40,
  KuaishouRtcEngineNotificationTypeLocalAudioStats = 41,
  KuaishouRtcEngineNotificationTypeLocalVideoStats = 42,
  KuaishouRtcEngineNotificationTypeRemoteAudioStats = 43,
  KuaishouRtcEngineNotificationTypeRemoteVideoStats = 44,
  KuaishouRtcEngineNotificationTypeNetworkQuality = 45,
  KuaishouRtcEngineNotificationTypeVideoTxSending = 46,
  KuaishouRtcEngineNotificationTypeVideoTxNotSending = 47,
  KuaishouRtcEngineNotificationTypeRtcMediaConnected = 48,
  KuaishouRtcEngineNotificationTypeRtcMediaDisconnected = 49,
  KuaishouRtcEngineNotificationTypeJoinChannelFailed = 50,
  KuaishouRtcEngineNotificationTypeMediaConfigUpdated = 51,
  KuaishouRtcEngineNotificationTypeAudioOutputDeviceChanged = 52,
  KuaishouRtcEngineNotificationTypeWarnAudioPlaybackDeviceUnavailable = 53,
  KuaishouRtcEngineNotificationTypeWarnAudioRecordingDeviceUnavailable = 54,
  KuaishouRtcEngineNotificationTypeErrAudioEngineUnavailable = 55,
  KuaishouRtcEngineNotificationTypeSetLiveTranscodingFailed = 56,
  KuaishouRtcEngineNotificationTypeAddPublishStreamingUrlFailed = 57,
  KuaishouRtcEngineNotificationTypeRemovePublishStreamingUrlFailed = 58,
  KuaishouRtcEngineNotificationTypeStopLiveTranscodingFailed = 59,
  KuaishouRtcEngineNotificationTypeVideoEncoderFatalError = 60,
  KuaishouRtcEngineNotificationTypeVideoDecoderFatalError = 61,
  KuaishouRtcEngineNotificationTypeLiveStreamStarted = 62,
  KuaishouRtcEngineNotificationTypeRemoteAudioFrozen = 63,
  KuaishouRtcEngineNotificationTypeRemoteVideoFrozen = 64,
  KuaishouRtcEngineNotificationTypeRemoteAudioRecovered = 65,
  KuaishouRtcEngineNotificationTypeRemoteVideoRecovered = 66,
  KuaishouRtcEngineNotificationTypeDebugInfo = 67,
  KuaishouRtcEngineNotificationTypeLeaveChannelResponse = 68,
  KuaishouRtcEngineNotificationTypeRemoteUplinkStats = 69,
  KuaishouRtcEngineNotificationTypeFirstLocalAudioFramePublished = 70,
  KuaishouRtcEngineNotificationTypeFirstLocalVideoFramePublished = 71,
  KuaishouRtcEngineNotificationTypeReceiveFirstAudioPacket = 72,
  KuaishouRtcEngineNotificationTypeReceiveFirstVideoPacket = 73,
  KuaishouRtcEngineNotificationTypeSignalingDisconnected = 74,
  KuaishouRtcEngineNotificationTypeConnectedWithMediaServer = 75,
  KuaishouRtcEngineNotificationTypeKtpConnecting = 76,
  KuaishouRtcEngineNotificationTypeKtpReconnecting = 77,
  KuaishouRtcEngineNotificationTypeParticipantOnline = 78,
  KuaishouRtcEngineNotificationTypeParticipantOffline = 79,
};

typedef NS_ENUM(NSInteger, KuaishouRtcStat) {
  KuaishouRtcStatIdle = 0,
  KuaishouRtcStatNoPublished = 1,
  KuaishouRtcStatPublishing = 2,
  KuaishouRtcStatPublished = 3,
};

typedef NS_ENUM(NSUInteger, KuaishouRtcEngineVideoRecordStateCode) {
  KuaishouRtcEngineVideoRecordStateCodeStarted = 0,
  KuaishouRtcEngineVideoRecordStateCodeStoppped = 1,
};

typedef NS_ENUM(NSInteger, KuaishouRtcEngineVideoRecordErrorCode) {
  KuaishouRtcEngineVideoRecordErrorCodeNoError = 0,
  KuaishouRtcEngineVideoRecordErrorCodeAlreadyStart = -901,
  KuaishouRtcEngineVideoRecordErrorCodeFileInvalid = -902,
  KuaishouRtcEngineVideoRecordErrorCodeNotStart = -903,
};

typedef NS_ENUM(NSInteger, KuaishouRtcEngineAudioTunnel) {
  KuaishouRtcEngineAudioTunnelWorld = 0,
  KuaishouRtcEngineAudioTunnelTeam = 1,
};

typedef NS_ENUM(NSInteger, KuaishouRtcEngineFetchAudioType) {
  KuaishouRtcEngineFetchAudio3DType = 1,
};

typedef NS_ENUM(NSInteger, KuaishouRtcEngineVideoCodecProfile) {
  KuaishouRtcEngineVideoCodecProfileBaseline = 66,
  KuaishouRtcEngineVideoCodecProfileMain = 77,
  KuaishouRtcEngineVideoCodecProfileHigh = 100,
};

typedef NS_ENUM(NSInteger, KuaishouRtcEngineAudioSampleRate) {
  KuaishouRtcEngineAudioSampleRate16000 = 16000,
  KuaishouRtcEngineAudioSampleRate32000 = 32000,
  KuaishouRtcEngineAudioSampleRate44100 = 44100,
  KuaishouRtcEngineAudioSampleRate48000 = 48000,
};

typedef NS_ENUM(NSInteger, KuaishouRtcEngineAudioCodecProfile) {
  KuaishouRtcEngineAudioCodecProfileLCAAC = 0,
  KuaishouRtcEngineAudioCodecProfileHEAAC = 1,
};

typedef NS_ENUM(NSInteger, KuaishouRtcEngineConnectionStateType) {
  KuaishouRtcEngineConnectionStateDisconnected = 1,
  KuaishouRtcEngineConnectionStateConnecting = 2,
  KuaishouRtcEngineConnectionStateConnected = 3,
  KuaishouRtcEngineConnectionStateReconnecting = 4,
  KuaishouRtcEngineConnectionStateFailed = 5,
};

typedef NS_ENUM(NSUInteger, KuaishouRtcEngineConnectionChangedReason) {
  KuaishouRtcEngineConnectionChangedUnknown = 0,
  KuaishouRtcEngineConnectionChangedConnecting,
  KuaishouRtcEngineConnectionChangedJoinSuccess,
  KuaishouRtcEngineConnectionChangedInterrupted,
  KuaishouRtcEngineConnectionChangedBannedByServer,
  KuaishouRtcEngineConnectionChangedJoinFailed,
  KuaishouRtcEngineConnectionChangedLeaveChannel,
  KuaishouRtcEngineConnectionChangedInvalidAppId,
  KuaishouRtcEngineConnectionChangedInvalidChannelName,
  KuaishouRtcEngineConnectionChangedInvalidToken,
  KuaishouRtcEngineConnectionChangedTokenExpired,
  KuaishouRtcEngineConnectionChangedRejectedByServer,
  KuaishouRtcEngineConnectionChangedSettingProxyServer,
  KuaishouRtcEngineConnectionChangedRenewToken,
  KuaishouRtcEngineConnectionChangedClientIpAddressChanged,
  KuaishouRtcEngineConnectionChangedKeepAliveTimeout,
  KuaishouRtcEngineConnectionChangedConnectFail,
  KuaishouRtcEngineConnectionChangedConnected,
};

typedef NS_ENUM(NSInteger, KuaishouRtcEngineRtmpStreamPublishState) {
  KuaishouRtcEngineRtmpStreamPublishStateIdle,
  KuaishouRtcEngineRtmpStreamPublishStateConnecting,
  KuaishouRtcEngineRtmpStreamPublishStateConnected,
  KuaishouRtcEngineRtmpStreamPublishStateRetrying,
  KuaishouRtcEngineRtmpStreamPublishStateFailed,
};

typedef NS_ENUM(NSInteger, KuaishouRtcEngineRtmpStreamPublishError) {
  KuaishouRtcEngineRtmpStreamPublishErrorOK,
  KuaishouRtcEngineRtmpStreamPublishErrorServerConnectFailed,
  KuaishouRtcEngineRtmpStreamPublishErrorRtmpConnectFailed,
  KuaishouRtcEngineRtmpStreamPublishErrorRtmpSendFailed,
  KuaishouRtcEngineRtmpStreamPublishErrorRtmpStreamEnd,
  KuaishouRtcEngineRtmpStreamPublishErrorRtmpStreamDeleted,
  KuaishouRtcEngineRtmpStreamPublishErrorUnknown,
};

typedef NS_ENUM(NSUInteger, KuaishouRtcEngineClientRoleType) {
  KuaishouRtcEngineClientRoleAnchor = 1,
  KuaishouRtcEngineClientRoleAudience = 2,
};

typedef NS_ENUM(NSUInteger, KuaishouRtcEngineUserOfflineReason) {
  KuaishouRtcEngineUserOfflineReasonQuit = 0,
  KuaishouRtcEngineUserOfflineReasonDropped = 1,
  KuaishouRtcEngineUserOfflineReasonBecomeAudience = 2,
};

typedef NS_ENUM(NSInteger, KuaishouRtcEngineAudioRouteType) {
  KuaishouRtcEngineAudioRouteTypeOutput = 0,
  KuaishouRtcEngineAudioRouteTypeInput = 1,
};

typedef NS_ENUM(NSInteger, KuaishouRtcEngineAudioRouting) {
  KuaishouRtcEngineAudioRoutingDefault = -1,
  KuaishouRtcEngineAudioRoutingHeadset = 0,
  KuaishouRtcEngineAudioRoutingEarpiece = 1,
  KuaishouRtcEngineAudioRoutingHeadsetNoMic = 2,
  KuaishouRtcEngineAudioRoutingSpeakerphone = 3,
  KuaishouRtcEngineAudioRoutingLoudspeaker = 4,
  KuaishouRtcEngineAudioRoutingHeadsetBluetooth = 5,
  KuaishouRtcEngineAudioRoutingUsb = 6,
  KuaishouRtcEngineAudioRoutingHdmi = 7,
  KuaishouRtcEngineAudioRoutingDisplayPort = 8,
  KuaishouRtcEngineAudioRoutingAirPlay = 9,
  KuaishouRtcEngineAudioRoutingBuiltInMic = 20,
};

typedef NS_ENUM(NSUInteger, KuaishouRtcEngineNetworkQuality) {
  KuaishouRtcEngineNetworkQualityUnknown = 0,
  KuaishouRtcEngineNetworkQualityExcellent = 1,
  KuaishouRtcEngineNetworkQualityGood = 2,
  KuaishouRtcEngineNetworkQualityPoor = 3,
  KuaishouRtcEngineNetworkQualityBad = 4,
  KuaishouRtcEngineNetworkQualityVBad = 5,
  KuaishouRtcEngineNetworkQualityUnavailable = 6,
};

typedef NS_ENUM(NSInteger, KuaishouRtcEngineRawAudioOperationMode) {
  KuaishouRtcEngineRawAudioOperationModeReadOnly = 0,
  KuaishouRtcEngineRawAudioOperationModeWriteOnly = 1, // not available
  KuaishouRtcEngineRawAudioOperationModeReadWrite = 2, // not available
};

typedef NS_ENUM(NSUInteger, KuaishouRtcEngineStreamFinishedReason) {
  KuaishouRtcEngineFileStreamFinishedNormal = 0,
  KuaishouRtcEngineFileStreamFinishedAbnormal = 1,
  KuaishouRtcEngineFileStreamFinishedDownloadError = 2,
  KuaishouRtcEngineFileStreamFinishedDiskFileOpenError = 3,
  KuaishouRtcEngineFileStreamFinishedDiskFileReadError = 4,
  KuaishouRtcEngineFileStreamFinishedAlreadyStarted = 5,
  KuaishouRtcEngineFileStreamFinishedSourceUrlEmpty = 6,
};

typedef NS_OPTIONS(NSUInteger, kuaishouRtcAudioEffectStateCode) {
  kuaishouRtcAudioEffectStateStarted = 1,
  kuaishouRtcAudioEffectStateFinished,
  kuaishouRtcAudioEffectStateError,
};

typedef NS_ENUM(NSInteger, kuaishouRtcAudioEffectErrorCode) {
  kuaishouRtcAudioEffectNoError = 0,
  kuaishouRtcAudioEffectErrorUnknown,
  kuaishouRtcAudioEffectErrorNotSupported,
  kuaishouRtcAudioEffectErrorIo,
  kuaishouRtcAudioEffectErrorMalformed,
};

typedef NS_ENUM(NSUInteger, KuaishouRtcEngineQosType) {
  KuaishouRtcEngineQosTypeUnknown = 0,
  KuaishouRtcEngineQosTypeRealtime = 1,
  KuaishouRtcEngineQosTypeSummary = 2,
  //KuaishouRtcEngineQosTypeRxDetails = 3,
  KuaishouRtcEngineQosTypeNetworkInfo = 4
};
