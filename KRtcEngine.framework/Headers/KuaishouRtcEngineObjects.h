#import <CoreGraphics/CoreGraphics.h>
#import <CoreVideo/CoreVideo.h>
#import <UIKit/UIKit.h>
#import "KuaishouRtcEngineEnumerates.h"

NS_ASSUME_NONNULL_BEGIN

@interface KuaishouRtcEngineJoinChannelParam : NSObject
@property(nonatomic, copy) NSString* token;
@property(nonatomic, copy) NSString* appId;
@property(nonatomic, copy) NSString* channelId;
@property(nonatomic, copy) NSString* userId;
@end

typedef int32_t KuaishouRtcEngineSourceId;

#pragma mark - KuaishouRtcEngineKtvBgmContext

@interface KuaishouRtcEngineKtvBgmContext : NSObject

@property(nonatomic) uint32_t startPos;   // unit: ms
@property(nonatomic) uint32_t endPos;     // unit: ms
@property(nonatomic) uint32_t progressPos; // unit: ms
@property(nonatomic) uint32_t fileDur; // unit: ms
@property(nonatomic) uint32_t realSingLyricsCnt;
@property(nonatomic) uint32_t shouldSingLyricsCnt;
@property(nonatomic) uint32_t totalLyricsCnt;

- (void)start;
- (void)start:(uint32_t)startPos;
- (void)end;
- (NSString*)getJson:(NSArray*)vadResultArray;

@end

#pragma mark - KuaishouRtcEngineVideoEncoderConfiguration

@interface KuaishouRtcEngineVideoEncoderConfiguration : NSObject

@property(nonatomic, assign) CGSize dimensions;

@property(nonatomic, assign) NSInteger frameRate;

@property(nonatomic, assign) NSInteger minFrameRate;

@property(nonatomic, assign) NSInteger bitrate;

@property(nonatomic, assign) NSInteger minBitrate;

@property(nonatomic, assign) NSInteger maxBitrate;

+ (KuaishouRtcEngineVideoEncoderConfiguration*)defaultLiveVideoEncoderConfig;

+ (KuaishouRtcEngineVideoEncoderConfiguration*)defaultRtcVideoEncoderConfig;

- (instancetype _Nonnull)initWithWidth:(NSInteger)width
                                height:(NSInteger)height
                             frameRate:(NSInteger)frameRate
                               bitrate:(NSInteger)bitrate;

@end

#pragma mark - KuaishouRtcEngineAudioFrame

@interface KuaishouRtcEngineAudioFrameExtendInfo : NSObject
@property(nonatomic, assign) uint32_t samplesPerChannel;
@property(nonatomic, assign) uint32_t bytesPerSample;
@property(nonatomic, assign) KuaishouRtcEngineRawAudioOperationMode operationMode;
@end

@interface KuaishouRtcEngineAudioFrame : NSObject

@property(nonatomic, strong) NSData*  data;
@property(nonatomic, assign) NSUInteger dataSize;
@property(nonatomic, assign) NSInteger sampleRate;
@property(nonatomic, assign) NSInteger channelNum;
@property(nonatomic, assign) uint64_t timestamp;
@property(nonatomic, assign) BOOL rawAudio;
@property(nonatomic, strong) KuaishouRtcEngineAudioFrameExtendInfo* extendInfo;

- (instancetype _Nonnull)initWithData:(uint8_t*)pcmData
                                 size:(size_t)pcmDataSize
                           sampleRate:(int32_t)sampleRate
                           channelNum:(int32_t)channelNum
                            timestamp:(uint64_t)timestamp
                             rawAudio:(BOOL)rawAudio;

@end

#pragma mark - KuaishouRtcEngineVideoFrame

@interface KuaishouRtcEngineVideoFrame : NSObject
  /* texture */
@property(nonatomic, assign) CVPixelBufferRef textureBuf;
@property(nonatomic, assign) int32_t rotation;  // only support in pixelbuf
/* raw */
@property(nonatomic, assign) uint8_t* dataBufY;
@property(nonatomic, assign) uint8_t* dataBufU;
@property(nonatomic, assign) uint8_t* dataBufV;
@property(nonatomic, assign) uint32_t width;
@property(nonatomic, assign) uint32_t height;
@property(nonatomic, assign) uint32_t strideY;
@property(nonatomic, assign) uint32_t strideU;
@property(nonatomic, assign) uint32_t strideV;
/* common */
@property(nonatomic, assign) uint64_t timestamp;
/* extentioin */
@property(nonatomic, assign) KuaishouRtcEngineVideoColorSpace colorSpace;
@property(nonatomic, assign) BOOL mirror;

- (instancetype)initWithI420Buffer:(uint8_t* [3])i420_planes line_size:(uint32_t[3])line_size width:(uint32_t)width height:(uint32_t)height timestamp:(uint64_t)timestamp;
@end

#pragma mark - KuaishouRtcEngineVideoQuality

@interface KuaishouRtcEngineVideoQuality : NSObject<NSSecureCoding>

  /**
   * psnr
   */
@property(nonatomic) double psnr;

/**
 * ssim
 */
@property(nonatomic) double ssim;

@end

#pragma mark - KuaishouRtcEngineVideoEncodedFrame

@interface KuaishouRtcEngineVideoEncodedFrame : NSObject<NSSecureCoding>

  /**
   * Frame encode data
   */
@property(nonatomic, strong) NSData* encodeData;

/**
 * width
 */
@property(nonatomic) uint32_t width;

/**
 * height
 */
@property(nonatomic) uint32_t height;

/**
 * pts_ms
 */
@property(nonatomic) uint64_t ptsMs;

/**
 * dts_ms
 */
@property(nonatomic) uint64_t dtsMs;

/**
 * frame type
 */
@property(nonatomic, assign) KuaishouRtcEngineVideoFrameType frameType;

/*
 * if YES, the frame is key frame.
 */
@property(nonatomic) BOOL keyFrame;

/**
 * video quality
 */
@property(nonatomic, strong) KuaishouRtcEngineVideoQuality* videoQuality;

/**
 * video rotation
 */
@property(nonatomic) uint8_t videoRotation;

/*
 * if YES, is base layer.
 */
@property(nonatomic) BOOL baseLayer;

/**
 * ref diff
 */
@property(nonatomic) uint8_t refDiff;

/**
 * Whether encoded frame or not
 */
@property(nonatomic) BOOL isEncodedSource;

/**
 * color space
 */
@property(nonatomic, assign) KuaishouRtcEngineVideoColorSpace colorSpace;

/**
 * fov id
 */
@property(nonatomic) uint8_t fovId;

/**
 * mix type
 */
@property(nonatomic, assign) KuaishouRtcEngineVideoMixType mixType;

/*
 * if YES, enable ltr.
 */
@property(nonatomic) BOOL enableLtr;

/**
 * fseq
 */
@property(nonatomic) uint16_t fSeq;

/**
 * gop seq
 */
@property(nonatomic) uint16_t gopSeq;

/**
 * fseq in gop
 */
@property(nonatomic) uint16_t fSeqInGop;

/**
 * ref seq in gop
 */
@property(nonatomic) uint16_t refSeqInGop;

/**
 * ltr frame type
 */
@property(nonatomic) uint8_t ltrFrameType;

/**
 * gop id
 */
@property(nonatomic) uint8_t gopId;

/**
 * priority
 */
@property(nonatomic) uint16_t priority;

/**
 * rtp to frame duration
 */
@property(nonatomic) uint64_t rtpToFrameDuration;

@end

@interface KuaishouRtcEngineFileStreamingConfig : NSObject

@property(nonatomic, copy) NSString* savePath;


- (instancetype _Nonnull)init;
@end

#pragma mark - KuaishouRtcEngineConfig

@interface KuaishouRtcEngineConfig : NSObject
  /**
   * Name of application which uses this SDK.
   * @note It MUST be set.
   */
@property(nonatomic, copy) NSString* appName;

/**
 * Version of application which uses this SDK.
 * @note It MUST be set.
 */
@property(nonatomic, copy) NSString* appVersion;

/**
 * UserID in the application which uses this SDK.
 * @note It MUST be set.
 */
@property(nonatomic, copy) NSString* appUserId;

/**
 * DeviceID a string to uniquely identify this device.
 * @note It's recommended to be set.
 */
@property(nonatomic, copy) NSString* deviceId;

/**
 * isAnchor anchor or not. Default is NO.
 */
@property(nonatomic) BOOL isAnchor;

/**
 * Qos enable flag.
 * @note See \ref KWAryaQosEnableFlag for details.
 */
@property(nonatomic) KuaishouRtcEngineQosEnableFlag qosEnableFlag;

/**
 * Qos upload interval. Unit: MilliSeconds.
 */
@property(nonatomic) int qosUploadInterval;

/**
 * Timeout value for MakeCall signaling. Unit: MilliSeconds.
 */
@property(nonatomic) uint32_t makeCallTimeoutMs;

/**
 * Enable video HEVC encoding or not.
 */
@property(nonatomic) BOOL videoHevcEnc;

/**
 * Enable video hardware encoding or not.
 */
@property(nonatomic) BOOL videoHwEnc;

/**
 * Video encoder configuration in json.
 * @note Use specified tool to generate it.
 */
@property(nonatomic, copy) NSString* _Nullable videoEncConfig;

/**
 * Arya configuration in json.
 */
@property(nonatomic, copy) NSString* _Nullable aryaConfig;

/**
 * Video target frame rate.
 */
@property(nonatomic) int videoFps;

/**
 * Video min frame rate for dynamic adaptation.
 */
@property(nonatomic) int videoMinFpsForAdapt;

/**
 * Video target width.
 * @note Set it to 0 if video's resolution is expected to change on the fly,
 * otherwise inputted video will be cropped/scaled to the given resolution.
 */
@property(nonatomic) uint32_t videoTargetWidth;

/**
 * Video target height.
 * @note Set it to 0 if video's resolution is expected to change on the fly,
 * otherwise inputted video will be cropped/scaled to the given resolution.
 */
@property(nonatomic) uint32_t videoTargetHeight;

/**
 * Cut video or not when inputted video does not match target resolution.
 * If YES, inputted video may be cut to target aspect ratio.
 * If NO, inputted video may be scaled and filled with black margin to match target rosolution.
*/
@property(nonatomic) BOOL videoEnableCutForVoiceParty;

/**
 * Enable Insert frame for chat stream.
 * If YES, will insert frame for chat stream, when no input video.
 * If NO, will not insert frame for chat stream, when no input video.
*/
@property(nonatomic) BOOL videoEnableInsertFrameForChat;

/**
 * Enable call session inner mix. Default: YES
 * For PK, mix sidebyside, others are overlay.
 */
@property(nonatomic) BOOL videoEnableInnerMix;

/**
 * Rotate inputted video if need.
 * @note Only for auto-rotation usage.
 * If YES && ((inputW > inputH && targetW < targetH) || (inputW < inputH && targetW > targetH)),
 * then rotate the captured video and add related info in flv_metadata for render usage.
 * The rotation will be done before cropping.
 */
@property(nonatomic) BOOL videoTryExchangeWidthAndHeight;

/**
 * Initial video encoding bitrate. Unit: kbps.
 */
@property(nonatomic) int videoInitBitrateKbps;

/**
 * Min video encoding bitrate. Unit: kbps.
 * Must be less than or equal with videoInitBitrateKbps.
 */
@property(nonatomic) int videoMinBitrateKbps;

/**
 * Max video encoding bitrate. Unit: kbps.
 * Must be more than or equal with videoInitBitrateKbps.
 */
@property(nonatomic) int videoMaxBitrateKbps;

/**
 * Video key frame interval (GoP). Unit: seconds.
 * @note Only valid in LiveStream mode.
 */
@property(nonatomic) int videoKeyFrameInterval;

/**
 * Stat period for notifying dropping video frames before encoding. Unit: MilliSeconds.
 */
@property(nonatomic) int videoDropBefEncStatPeriodMs;

/**
 * If fps of dropped video frames before encoding is larger than this value, there will be a notify callback.
 */
@property(nonatomic) int videoDropBefEncAvgFpsToNotify;

/**
 * In LiveChat scene, guest video will be mixed into anchor's video.
 * left in range [0.0, 1.0]
 */
@property(nonatomic) float videoGuestPositionLeft;

/**
 * In LiveChat scene, guest video will be mixed into anchor's video.
 * top in range [0.0, 1.0]
 */
@property(nonatomic) float videoGuestPositionTop;

/**
 * In LiveChat scene, guest video will be mixed into anchor's video.
 * width in range [0.0, 1.0]
 */
@property(nonatomic) float videoGuestPositionWidth;

/**
 * In LiveChat scene, guest video will be mixed into anchor's video.
 * height in range [0.0, 1.0]
 */
@property(nonatomic) float videoGuestPositionHeight;

/**
 * Speaker inactive min interval milliseconds.
 */
@property(nonatomic) int speakerInactiveMinIntervalMs;

/**
 * Enable local loopback mode or not.
 * @note Only for debug.
 */
@property(nonatomic) BOOL localLoopback;

/**
 * Dump enable flag.
 * @note Only for debug.
 */
@property(nonatomic) uint32_t dumpEnableFlag;

/**
 * Enable upload call info to Kibana.
 * @note Only for debug.
 */
@property(nonatomic) BOOL enableNeedleLog;

/**
 * Enable video encoder test or not, default: NO
 */
@property(nonatomic) BOOL enableVEncTest;

/**
 * Whether to use offline record, default: NO
 */
@property(nonatomic) BOOL useOfflineRecord;

/**
 * Whether need to mux when use offline record, default: YES
 */
@property(nonatomic) BOOL offlineRecordNeedMux;

/**
 * Whether need to drop frame when use offline record, default: NO
 */
@property(nonatomic) BOOL offlineRecordDropFrame;

/**
 * Offline record media mode
 */
@property(nonatomic) KuaishouRtcEngineMediaMode offlineRecordMediaMode;

/**
 * Rtc  media mode
 */
@property(nonatomic) KuaishouRtcEngineMediaMode rtcMediaMode;

/**
 * Video preview width.
 */
@property(nonatomic) uint32_t videoPreviewWidth;

/**
 * Video preview height.
 */
@property(nonatomic) uint32_t videoPreviewHeight;

/**
 * Video capture width.
 */
@property(nonatomic) uint32_t videoCaptureWidth;

/**
 * Video capture height.
 */
@property(nonatomic) uint32_t videoCaptureHeight;

/**
 * Path to save dump files.
 * @note Only for debug.
 */
@property(nonatomic, copy) NSString* _Nullable dumpPath;

/**
 * Path to save files.
 * @note Only for debug.
 */
@property(nonatomic, copy) NSString* _Nullable documentRootPath;

/**
 * Use external audio device, default: NO
 */
@property(nonatomic) BOOL useExternalAudioDevice;

/**
 * Use audio player, default: YES
 */
@property(nonatomic) BOOL enableExtraAudioPlayer;

/**
 * Enable audio pre process, default: YES
 */
@property(nonatomic) BOOL enableAudioPreProcess;

/**
 * Enable frame rate dynamic adaptation or not.
 */
@property(nonatomic) BOOL enableFrameRateDynAdapt;


/**
 * Enable get active speaker list and voice energy
 */
@property(nonatomic) BOOL enableAudioVad;

/**
 * Enable mix with other audio app.
 */
@property(nonatomic) BOOL mixWithOtherAudio;

/**
 * Enable net state dectet or not, default: NO
 */
@property(nonatomic) BOOL enableNetState;

/**
 * Enable low memory or not, default: NO
 */
@property(nonatomic) BOOL enableLowMemory;

/**
 * Capacity for raw video pool
 */
@property(nonatomic) uint32_t videoPoolCapacity;

/**
 * Append sth. in LiveStream metadata. Player will show it in debug info.
 */
@property(nonatomic, copy) NSString* _Nullable debugInfoInMeta;

/**
 * Capacity for moments, unit: ms
 */
@property(nonatomic) uint32_t momentsCapacityMs;


/**
 * Enable the feature of video request or not, default:NO
 * YES:  Application can request the video of interested participant;
 * NO: Videos of all participants will be received.
 */
@property(nonatomic) BOOL enableVideoRequest;

/**
 * Request all videos or not, default:YES
 * YES:  reuqest all videos via arya internally;
 * NO: no video will be received unless requestVideoForParticipants is invoked.
 */
@property(nonatomic) BOOL requestAllVideos;

/**
 * Whether enable live stream fill black margin
 */
@property(nonatomic) BOOL liveStreamKeepAspectRatio;

/**
 * X valule of live stream effective area when enable liveStreamKeepAspectRatio
 */
@property(nonatomic) float liveStreamEffectiveAreaX;

/**
 * Y valule of live stream effective area when enable liveStreamKeepAspectRatio
 */
@property(nonatomic) float liveStreamEffectiveAreaY;

/**
 *User's initial network type, networkChanged should be invoked to update the network type during the call
 */
@property(nonatomic) KuaishouRtcEngineNetworkType userNetworkType;

/**
 *see https://wiki.corp.kuaishou.com/pages/viewpage.action?pageId=355247287
 */
@property(nonatomic, copy) NSString* _Nullable freeTrafficFlag;

/**
 * Enable debug info callback  or not, default:NO
 * YES:  OnDebugInfo will be called with debug info of json format
 */
@property(nonatomic) BOOL enableDebugInfo;

@property(nonatomic, copy) NSString* _Nullable edgeGroupAddr;

@property(nonatomic) BOOL enableOpenApi;

@end


#pragma mark - KWAryaVideoWatermark

@interface KWAryaVideoWatermark : NSObject
  /*
   * logo image data with rgba format.
   */
@property(nonatomic) uint8_t* rgba;
/*
 * logo width. must be even number.
 */
@property(nonatomic) uint32_t w;
/*
 * logo height. must be even number.
 */
@property(nonatomic) uint32_t h;
/*
 * x-coordination value of left top corner. should be 0 to 1.
 */
@property(nonatomic) float x;
/*
 * y-coordination value of left top corner. should be 0 to 1.
 */
@property(nonatomic) float y;
/*
 * color space.
 */
@property(nonatomic) KuaishouRtcEngineBitmapColorSpace colorSpace;
/*
 * logoInRtc logo available in rtc.
 */
@property(nonatomic) BOOL logoInRtc;
@end

#pragma mark - KuaishouRtcEngineVideoQuality

@interface KuaishouRtcUserInfo : NSObject
@property(nonatomic, copy) NSString* userId;
@property(nonatomic, assign) uint32_t videoSourceType;
@property(nonatomic, assign) uint32_t sessionId;
@property(nonatomic, assign) uint32_t videoSimulcastId;
@property(nonatomic, assign) BOOL enableAudioTx;
@property(nonatomic, assign) BOOL enableVideoTx;
@end

#pragma mark - Qos

@interface KuaishouRtcEngineQosInfo : NSObject

@property(nonatomic, copy) NSString* rtmpHostIP;        // 直播节点ip
@property(nonatomic, copy) NSString* serverMode;        // 服务器类型: cdn or 源站
@property(nonatomic, copy) NSString* idc;               // idc信息
@property(nonatomic, copy) NSString* role;              // 角色
@property(nonatomic, copy) NSString* sdkVersion;        // sdk版本号
@property(nonatomic, copy) NSString* liveStreamId;      // 当前直播Id
@property(nonatomic, copy) NSString* pushUrl;           // 直播推流的地址
@property(nonatomic, assign) int32_t uploadedKByte;     // 流量(单位：KByte)
@property(nonatomic, assign) int32_t encodedFrames;     // 视频编码帧数
@property(nonatomic, assign) int32_t droppedVideoFrames;// 丢帧次数
@property(nonatomic, assign) int32_t rtUploadNum;       // 实时上报条数
@property(nonatomic, assign) int32_t errorCode;         // 直播异常退出的错误码
@property(nonatomic, assign) int32_t blockCnt;          // 卡顿次数
@property(nonatomic, assign) int32_t retryCnt;          // 重试次数
@property(nonatomic, assign) int32_t liveEncodeType;    // 推流的编码类型
@property(nonatomic, assign) int32_t fsRxBlockCnt;      // File streaming 接受block数
@property(nonatomic, assign) int32_t fsTxBlockCnt;      // File streaming 发送block数
@property(nonatomic, assign) int32_t fsRxPktCnt;        // File streaming 接受packet数
@property(nonatomic, assign) int32_t fsRxPktKByte;       // File streaming 发送packet数
@property(nonatomic, assign) int32_t fsRxDropFrmCnt;    // File streaming 接受丢frame数
@property(nonatomic, assign) int64_t livePushStartTime; // 直播推流开始时间(单位：ms)
@property(nonatomic, assign) int64_t livePushEndTime;   // 直播推流结束时间(单位：ms)
@property(nonatomic, assign) int64_t totalDuration;     // 直播全部时长(单位：ms)
@property(nonatomic, assign) int64_t callerCallingTime; // 主叫开始呼叫时间(单位：ms)
@property(nonatomic, assign) int64_t callerConnectedTime;// 呼叫成功时间(单位：ms)
@property(nonatomic, assign) int64_t callerNegotiationTime;// 呼叫成功建立时间(单位：ms)
@property(nonatomic, assign) int64_t fsRxBlockTotalTime;// File streaming 接受block总时间(单位：ms)
@property(nonatomic, assign) int64_t fsDuration;        // File streaming 总时长(单位：ms)
@property(nonatomic, assign) int64_t cpuFreqUpCnt;      // CPU升频总次数
@property(nonatomic, assign) int64_t cpuFreqDnCnt;      // CPU降频总次数
@property(nonatomic, assign) float encodeVKbps;         // 已编码的视频比特数(单位：kbits)
@property(nonatomic, assign) float encodeAKbps;         // 已编码的音频比特数(单位：kbits)
@end

@interface KuaishouRtcEngineChannelStats : NSObject

@property(nonatomic, copy) NSString* channelId;
@property(assign, nonatomic) uint32_t txKBitrate;
@property(assign, nonatomic) uint32_t rxKBitrate;
@property(assign, nonatomic) uint32_t txAudioKBitrate;
@property(assign, nonatomic) uint32_t rxAudioKBitrate;
@property(assign, nonatomic) uint32_t txVideoKBitrate;
@property(assign, nonatomic) uint32_t rxVideoKBitrate;
@property(assign, nonatomic) uint32_t cpuAppUsage;
@property(assign, nonatomic) uint32_t cpuTotalUsage;
@property(assign, nonatomic) int64_t memoryAppUsageInKbytes;
@property(assign, nonatomic) uint32_t networkRtt;
@property(assign, nonatomic) BOOL hasConnected; // not in summary
@property(assign, nonatomic) BOOL viaProxy;     // not in summary

/* summary only */
@property(assign, nonatomic) int64_t duration;
@property(assign, nonatomic) int64_t txBytes;
@property(assign, nonatomic) int64_t rxBytes; // TODO
@property(assign, nonatomic) int64_t txAudioBytes;
@property(assign, nonatomic) int64_t txVideoBytes;
@property(assign, nonatomic) int64_t rxAudioBytes;
@property(assign, nonatomic) int64_t rxVideoBytes;
@property(assign, nonatomic) uint32_t txPacketLossRate;
@property(assign, nonatomic) uint32_t userCount;

@end

@interface KuaishouRtcEngineLocalVideoStats : NSObject
@property(nonatomic, copy) NSString* channelId;
@property(assign, nonatomic) NSUInteger targetBitrate;
@property(assign, nonatomic) NSUInteger encodedBitrate;
@property(assign, nonatomic) NSUInteger sentBitrate;
@property(assign, nonatomic) NSUInteger captureFrameRate;
@property(assign, nonatomic) NSUInteger targetFrameRate;
@property(assign, nonatomic) NSUInteger encoderOutputFrameRate;
@property(assign, nonatomic) NSUInteger encodedFrameWidth;
@property(assign, nonatomic) NSUInteger encodedFrameHeight;
@end

@interface KuaishouRtcEngineRemoteVideoStats : NSObject
@property(nonatomic, copy) NSString* channelId;
@property(nonatomic, copy) NSString* uid;
@property(assign, nonatomic) NSUInteger delay;
@property(assign, nonatomic) NSUInteger width;
@property(assign, nonatomic) NSUInteger height;
@property(assign, nonatomic) NSUInteger receivedBitrate;
@property(assign, nonatomic) NSUInteger decoderOutputFrameRate;
@property(assign, nonatomic) NSUInteger rendererOutputFrameRate;
@property(assign, nonatomic) NSUInteger packetLossRate;
@end

@interface KuaishouRtcEngineLocalAudioStats : NSObject
@property(nonatomic, copy) NSString* channelId;
@property(assign, nonatomic) NSUInteger numChannels;
@property(assign, nonatomic) NSUInteger sentSampleRate;
@property(assign, nonatomic) NSUInteger sentBitrate;
@end

@interface KuaishouRtcEngineRemoteAudioStats : NSObject
@property(nonatomic, copy) NSString* channelId;
@property(nonatomic, copy) NSString* uid;
@property(assign, nonatomic) NSUInteger networkTransportDelay;
@property(assign, nonatomic) NSUInteger audioLossRate;
@property(assign, nonatomic) NSUInteger numChannels;
@property(assign, nonatomic) NSUInteger receivedSampleRate;
@property(assign, nonatomic) NSUInteger receivedBitrate;
@end

@interface KuaishouRtcEngineNetworkStats : NSObject
@property(nonatomic, copy) NSString* channelId;
@property(assign, nonatomic) NSInteger rtt;
@property(assign, nonatomic) NSInteger uplinkLostRate;
@property(assign, nonatomic) NSInteger downlinkLostRate;
@property(assign, nonatomic) NSInteger uplinkBandwidth;
@property(assign, nonatomic) NSInteger downlinkBandwidth;
@property(assign, nonatomic) BOOL uplinkIsGood;
@property(assign, nonatomic) BOOL downlinkIsGood;
@property(assign, nonatomic) BOOL hasConnected;
@property(assign, nonatomic) BOOL viaProxy;
@end

/**
 * Participant Media Info
 */
@interface KuaishouRtcEngineParticipantMediaInfo : NSObject

  /**
   * User Id.
   */
@property(nonatomic, copy) NSString* userId;

/**
 * Channel Id.
 */
@property(nonatomic, copy) NSString* channelId;

/**
 * Video source type: 0: people, 1: content
 */
@property(nonatomic) uint32_t videoSourceType;

/**
 * Session Id: used for krtc
 */
@property(nonatomic) uint32_t sessionId;
@end

/**
 * Layout item for one video
 */
@interface KuaishouRtcEngineLayoutItem : NSObject

  /**
   * The x coordinate of video left top
   */
@property(nonatomic) float x;

/**
 * The y coordinate of video left top
 */
@property(nonatomic) float y;

/**
 * The width of the video
 */
@property(nonatomic) float w;

/**
 * The height of the video
 */
@property(nonatomic) float h;

/**
 * The media info of the video
 */
@property(nonatomic, strong) KuaishouRtcEngineParticipantMediaInfo* mediaInfo;
@end

/**
 * KuaishouRtcEngineMicrophoneInfo
 */

@interface KuaishouRtcEngineMicrophoneInfo : NSObject
@property(nonatomic, assign) BOOL mute;
@property(nonatomic, assign) NSInteger energy;
@property(nonatomic, assign) NSInteger vad;
@property(nonatomic, assign) NSInteger currentVolume;
@property(nonatomic, assign) NSInteger suggestedVolume;
@end

@interface KuaishouRtcEngineVideoCanvas : NSObject

@property(nonatomic, copy) NSString* _Nullable channelId;
@property(nonatomic, copy) NSString* _Nullable uid;
@property(nonatomic, assign) KuaishouRtcEngineVideoRenderMode renderMode;
@property(nonatomic, assign) KuaishouRtcEngineVideoMirrorMode mirrorMode;

- (instancetype _Nonnull)initWithUIView:(UIView*)view
                                channel:(NSString*)channelId
                                    uid:(NSString*)uid
                             renderMode:(KuaishouRtcEngineVideoRenderMode)renderMode
                             mirrorMode:(KuaishouRtcEngineVideoMirrorMode)mirrorMode;

- (void)displayPixelBuffer:(CVPixelBufferRef)pixelBuffer
               andRotation:(int32_t)rotation;

- (void)displayVideoFrame:(KuaishouRtcEngineVideoFrame*)frame;

- (void)displayVideoFrame:(uint8_t* _Nonnull [_Nonnull 3])i420_planes
  line_size:(uint32_t[_Nonnull 3])line_size
      width:(uint32_t)width
     height:(uint32_t)height
  timestamp:(uint64_t)timestamp
color_space:(int32_t)color_space
     mirror:(BOOL)mirror
   rotation:(int32_t)rotation;

@end

@interface KuaishouRtcEngineVideoLayout : NSObject
@property(nonatomic, assign) uint64_t userId;
@property(nonatomic, assign) BOOL isScreenSharing;
@property(nonatomic, assign) BOOL isMuted;
@property(nonatomic, assign) int layoutX;
@property(nonatomic, assign) int layoutY;
@property(nonatomic, assign) int layoutW;
@property(nonatomic, assign) int layoutH;
@end

@interface KuaishouRtcEngineLiveTranscoding : NSObject
// video configs
@property(nonatomic, assign) int width;
@property(nonatomic, assign) int height;
@property(nonatomic, assign) int videoBitrate;
@property(nonatomic, assign) int videoFramerate;
@property(nonatomic, assign) int videoGop;
@property(nonatomic, assign) KuaishouRtcEngineVideoCodecProfile videoCodecProfile;

// audio configs
@property(nonatomic, assign) int audioBitrate;
@property(nonatomic, assign) int audioChannels;
@property(nonatomic, assign) KuaishouRtcEngineAudioSampleRate audioSampleRate;
@property(nonatomic, assign) KuaishouRtcEngineAudioCodecProfile audioCodecProfile;

// video layout
@property(nonatomic, strong) NSMutableArray<KuaishouRtcEngineVideoLayout*>* transcodingUsers;
- (NSString*)toJson;
@end

@interface KuaishouRtcEngineAudioVolumeInfo : NSObject
@property(nonatomic, assign) int uid;
@property(nonatomic, assign) int volume;
@property(nonatomic, assign) int vad;
@property(nonatomic, copy) NSString* channelId;
@end

NS_ASSUME_NONNULL_END
