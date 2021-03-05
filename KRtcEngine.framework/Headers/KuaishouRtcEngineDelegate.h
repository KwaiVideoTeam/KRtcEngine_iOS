#import "KuaishouRtcEngineEnumerates.h"
#import "KuaishouRtcEngineObjects.h"

NS_ASSUME_NONNULL_BEGIN

@class KuaishouRtcEngine;
@class KuaishouRtcEngineVideoFrame;
@class KuaishouRtcEngineAudioFrame;

@protocol KuaishouRtcEngineDelegate <NSObject>
@optional

#pragma mark - Core Delegate Methods

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
                  channel:(NSString*)channel
          didOccurWarning:(KuaishouRtcWarningCode)warningCode;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
                  channel:(NSString*)channel
            didOccurError:(KuaishouRtcErrorCode)errorCode;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
           didJoinChannel:(NSString*)channel
                  withUid:(NSString*)uid
                  elapsed:(NSInteger)elapsed;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
  didLeaveChannelWithStats:(KuaishouRtcEngineChannelStats*)stats;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
                channelId:(NSString*)channelId
     didClientRoleChanged:(KuaishouRtcEngineClientRoleType)oldRole
                  newRole:(KuaishouRtcEngineClientRoleType)newRole;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
           didJoinedOfUid:(NSString*)uid
                channelId:(NSString*)channelId
                  elapsed:(NSInteger)elapsed;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
          didOfflineOfUid:(NSString*)uid
                channelId:(NSString*)channelId
                   reason:(KuaishouRtcEngineUserOfflineReason)reason;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
                   channel:(NSString*)channel
  connectionChangedToState:(KuaishouRtcEngineConnectionStateType)state
                    reason:(KuaishouRtcEngineConnectionChangedReason)reason;

- (void)kuaishouRtcEngineConnectionDidLost:(KuaishouRtcEngine*)engine;


#pragma mark - Media Delegate Methods

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
            activeSpeaker:(NSArray*)speakerUids;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
    audioVolumeIndication:(NSArray<KuaishouRtcEngineAudioVolumeInfo*>*)audioInfo
           andTotalVolume:(int)totalVolume;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
    localAudioStateChange:(KuaishouRtcEngineLocalAudioState)state
                    error:(KuaishouRtcEngineLocalAudioError)error;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine localVideoStateChange:(KuaishouRtcEngineLocalVideoStreamState)state
                    error:(KuaishouRtcEngineLocalVideoStreamError)error;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
     firstLocalAudioFrame:(NSInteger)elapsed;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
  firstLocalVideoFrameWithSize:(CGSize)size
                       elapsed:(NSInteger)elapsed;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
  onFirstLocalAudioFramePublished:(uint64_t)elapse;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
  onFirstLocalVideoFramePublished:(uint64_t)elapse;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
  didAudioPublishStateChange:(KuaishouRtcStat)oldState
                    newState:(KuaishouRtcStat)newState
        elapseSinceLastState:(uint64_t)elapseSinceLastState;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
  didVideoPublishStateChange:(KuaishouRtcStat)oldState
                    newState:(KuaishouRtcStat)newState
        elapseSinceLastState:(uint64_t)elapseSinceLastState;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
  remoteAudioStateChangedOfUid:(NSString*)uid
                       channel:(NSString*)channel
                         state:(KuaishouRtcEngineRemoteAudioState)state
                        reason:(KuaishouRtcEngineRemoteAudioStateReason)reason
                       elapsed:(NSInteger)elapsed;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
  remoteVideoStateChangedOfUid:(NSString*)uid
                       channel:(NSString*)channel
                         state:(KuaishouRtcEngineRemoteVideoState)state
                        reason:(KuaishouRtcEngineRemoteVideoStateReason)reason
                       elapsed:(NSInteger)elapsed;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
  firstRemoteVideoFrameOfUid:(NSString*)uid
                     channel:(NSString*)channel
                        size:(CGSize)size
                     elapsed:(NSInteger)elapsed;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
    videoSizeChangedOfUid:(NSString*)uid
                  channel:(NSString*)channel
                     size:(CGSize)size
                 rotation:(NSInteger)rotation;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
                  channel:(NSString*)channel
                      uid:(NSString*)uid
          remoteAudioMute:(BOOL)remoteAudioMute;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
                  channel:(NSString*)channel
                      uid:(NSString*)uid
          remoteVideoMute:(BOOL)remoteVideoMute;


#pragma mark - Device Delegate Methods

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
     didAudioRouteChanged:(KuaishouRtcEngineAudioRouting)route;


#pragma mark - Statistics Delegate Methods

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
          lastmileQuality:(KuaishouRtcEngineNetworkQuality)quality;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
               onRtcStats:(KuaishouRtcEngineChannelStats*)rtcStats;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
        onLocalVideoStats:(KuaishouRtcEngineLocalVideoStats*)localVideoStats;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
       onRemoteVideoStats:(KuaishouRtcEngineRemoteVideoStats*)remoteVideoStats;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
        onLocalAudioStats:(KuaishouRtcEngineLocalAudioStats*)localAudioStats;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
       onRemoteAudioStats:(KuaishouRtcEngineRemoteAudioStats*)remoteAudioStats;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
         onNetworkQuality:(KuaishouRtcEngineNetworkStats*)networkStats;


#pragma mark - Audio Player Delegate Methods

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
  localAudioMixingStateDidChanged:(KuaishouRtcEngineAudioMixingStateCode)state
                        errorCode:(KuaishouRtcEngineAudioMixingErrorCode)errorCode;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
  localAudioMixingProgress:(float)position
                  duration:(float)duration;

- (void)kuaishouRtcEngineLocalAudioMixingDidFinish:(KuaishouRtcEngine*)engine;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
  audioEffectStateDidChanged:(kuaishouRtcAudioEffectStateCode)state
                   errorCode:(kuaishouRtcAudioEffectErrorCode)errorCode
                    fileName:(NSString*)fileName;


#pragma mark - Live Transcoding Delegate Methods

- (void)kuaishouRtcEngineRtmpStreamingStateChanged:(KuaishouRtcEngine*)engine
                                           channel:(NSString*)channel
                                               url:(NSString*)rtmpUrl
                                            status:(KuaishouRtcEngineRtmpStreamPublishState)status
                                             error:(KuaishouRtcEngineRtmpStreamPublishError)error;


#pragma mark - Inject Stream URL Delegate Methods

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
    fileStreamStatusOfUrl:(NSString*)url
                   status:(KuaishouRtcEngineFileStreamStatus)status;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
  fileStreamPositionOfUrl:(NSString*)url
                 position:(int64_t)position duration:(int64_t)duration;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
  fileStreamVideoDecodedOfUrl:(NSString*)url
                        frame:(KuaishouRtcEngineVideoFrame*)frame;


#pragma mark - Stream Message Delegate Methods

/**
 * The callback when received pass through data
 * @param engine KuaishouRtcEngine
 * @param userId peer user id
 * @param channel channel id
 * @param data pass through data
 */
- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
  receiveStreamMessageFromUid:(NSString*)userId
                      channel:(NSString*)channel
                         data:(NSData*)data;


#pragma mark - Media Data Delegate Methods

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
     localVideoPreEncoded:(KuaishouRtcEngineVideoFrame*)frame;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
        localVideoEncoded:(NSString*)channel frame:(KuaishouRtcEngineVideoEncodedFrame*)frame;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
  remoteVideoPreDecodedOfUid:(NSString*)uid
                     channel:(NSString*)channel
                       frame:(KuaishouRtcEngineVideoEncodedFrame*)frame;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
  remoteVideoDecodedOfUid:(NSString*)uid
                  channel:(NSString*)channel
                    frame:(KuaishouRtcEngineVideoFrame*)frame;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
     localAudioPreEncoded:(KuaishouRtcEngineAudioFrame*)frame;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
        localAudioEncoded:(KuaishouRtcEngineAudioFrame*)frame;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
  remoteAudioPreDecodedOfUid:(NSString*)uid
                     channel:(NSString*)channel
                       frame:(KuaishouRtcEngineAudioFrame*)frame;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
  remoteAudioDecodedOfUid:(NSString*)uid
                  channel:(NSString*)channel
                    frame:(KuaishouRtcEngineAudioFrame*)frame;


#pragma mark - Record Delegate Methods

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
  videoRecordStateDidChanged:(KuaishouRtcEngineVideoRecordStateCode)state
                   errorCode:(KuaishouRtcEngineVideoRecordErrorCode)errorCode
                    fileName:(NSString*)fileName;


- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
  audioRecordingStateDidChanged:(KuaishouRtcAudioRecordingStateCode)state
                      errorCode:(KuaishouRtcAudioRecordingErrorCode)errorCode;

#pragma mark - Custom Delegate Methods

/**
 * The callback when peer mute status updated
 * @param engine KuaishouRtcEngine
 * @param userId peer user id
 * @param channel channel id
 * @param audioMute whether peer audio mute
 * @param videoMute whether peer video mute
 */
- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
  onPeerMuteStatusUpdatedFromUid:(NSString*)userId
                         channel:(NSString*)channel
                   withAudioMute:(BOOL)audioMute
                   withVideoMute:(BOOL)videoMute;


- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
    onKaraokeScoreUpdated:(NSString*)songId
                wordScore:(int)wordScore
               totalscore:(int)totalScore
                 rowIndex:(int)rowIndex;

/**
 The callback to receive events that audio buffer is finished.
 @param bufferId user defined.
 */
- (void)kuaishouRtcEngineAudioBufferPlayFinished:(NSString*)bufferId;

/**
 The callback to receive audio segment progress update
 @param position audio segment position in float
 @param duration aduio segment duration in float
 */
- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
  audioSegmentProgressedWithPosition:(float)position
                            duration:(float)duration;

/**
 The callback to receive error events
 @param url audio segment play file url
 @param error audio segment play error
 */
- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
  audioSegmentPlayFinishedWithUrl:(NSString*)url
                            error:(KuaishouRtcEngineBgmError)error;

/**
 Handle qos messages of given type
 @param type qos type
 @param message qos message
 */
- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
       qosMessageWithType:(KuaishouRtcEngineQosType)type
                  message:(NSString*)message;

/**
 * The callback when some status changed in call
 * @param channelId channel Id
 * @param type notification type
 */
- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
    onNotifyWithChannelId:(NSString*)channelId
                 withType:(KuaishouRtcEngineNotificationType)type;

/**
 * The callback when got media server infomation
 * @param ip IP address of media server
 * @param port Port of media server
 * @param isLiveStream is LiveStream or not
 */
- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
  onMediaServerInfoWithChannelId:(NSString*)channelId
                           andIp:(NSString*)ip
                         andPort:(int)port
                 andIsLiveStream:(BOOL)isLiveStream;

/**
 * The callback when video send resolution is changed
 * @param width video width
 * @param height video height
 * @param fps video frame rate
 */
- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
  onVideoSendParamChangedWithWidth:(int)width
                        withHeight:(int)height
                           withFps:(int)fps;


- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
    onAudioPassThroughMsg:(NSString*)callId
                     data:(NSData*)data;

- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
           onVoiceComment:(NSString*)callId
                     data:(NSData*)data;


- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
             withSendData:(NSData*)data;

/**
 The callback to receive offset in live stream
 @param offset bgm offset in live stream
 */
- (void)kuaishouRtcEngine:(KuaishouRtcEngine*)engine
    bgmOffsetInLiveStream:(uint32_t)offset;

@end

NS_ASSUME_NONNULL_END
