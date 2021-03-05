#import <Foundation/Foundation.h>
#import <CoreMedia/CMSampleBuffer.h>
#import "KuaishouRtcEngineObjects.h"
#import "KuaishouRtcEngineAudioFrameDelegate.h"
#import "KuaishouRtcEngineDelegate.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark - KuaishouRtcEngine

@interface KuaishouRtcEngine : NSObject

#pragma mark - Core Service

- (instancetype _Nonnull)initEngineWithConfig:(KuaishouRtcEngineConfig* _Nonnull)config
                                     delegate:(id<KuaishouRtcEngineDelegate> _Nullable)delegate;
- (void)destroy;

- (int)setClientRole:(NSString*)channelId
      clientRoleType:(KuaishouRtcEngineClientRoleType)role;

- (int)joinChannelByParam:(KuaishouRtcEngineJoinChannelParam* _Nullable)param;

- (int)leaveChannel:(NSString*)channelId
         leaveBlock:(void(^ _Nullable)(KuaishouRtcEngineChannelStats* _Nonnull stat))leaveChannelBlock;


#pragma mark - Core Audio

- (int)enableAudio;

- (int)disableAudio;

- (int)adjustRecordingVolume:(NSInteger)volume;

- (int)adjustPlaybacklVolume:(NSInteger)volume;

- (int)enableAudioVolumeIndication:(NSInteger)interval
                            smooth:(NSInteger)smooth
                        report_vad:(BOOL)report_vad;

- (int)disableLocalAudioVolumeIndication;

- (int)enableLocalAudio;

- (int)disableLocalAudio;

- (int)muteLocalAudioStream;

- (int)unmuteLocalAudioStream;

- (int)enableLocalAudioComfortableNoise;

- (int)disableLocalAudioComfortableNoise;

- (int)muteRemoteAudioStream:(NSString*)channel
                         uid:(NSString*)uid;

- (int)unmuteRemoteAudioStream:(NSString*)channel
                           uid:(NSString*)uid;

- (int)muteAllRemoteAudioStreams:(NSString*)channel;

- (int)unmuteAllRemoteAudioStreams:(NSString*)channel;

- (int)muteAllRemoteAudioStreams;

- (int)unmuteAllRemoteAudioStreams;

- (int)muteSpeaker;

- (int)unmuteSpeaker;

- (int)setDefaultMuteAllRemoteAudioStreams:(BOOL)mute;

- (int)adjustUserPlaybackVolume:(NSString*)channel
                            uid:(NSString*)uid
                         volume:(int)volume;

- (int)enableNoiseSuppression;

- (int)disableNoiseSuppression;


#pragma mark - Core Video

// Enables the video module.
- (int)enableVideo;

// Disables the video module.
- (int)disableVideo;

// Set the video encoder configuration.
- (int)setVideoEncoderConfiguration:(NSString*)channelId videoEncoderConfig:(KuaishouRtcEngineVideoEncoderConfiguration* _Nonnull)videoEncoderConfig;

// Enable the local video.
- (int)enableLocalVideo;

// Disables the local video.
- (int)disableLocalVideo;

// Stop sending the local video stream.
- (int)muteLocalVideoStream:(NSString*)channel;

// Start sending the local video stream.
- (int)unmuteLocalVideoStream:(NSString*)channel;

// Stop receiving a specified remote user’s video stream.
- (int)muteRemoteVideoStream:(NSString*)channel uid:(NSString*)uid;

// Start receiving a specified remote user’s video stream.
- (int)unmuteRemoteVideoStream:(NSString*)channel uid:(NSString*)uid;

// Stop receiving all remote video streams.
- (int)pauseAllRemoteVideoStreams:(NSString*)channel;

// Start receiving all remote video streams.
- (int)resumeAllRemoteVideoStreams:(NSString*)channel;

// Set not receive all remote video streams by default.
- (int)setDefaultMuteAllRemoteVideoStreams;

// Set receive all remote video streams by default.
- (int)setDefaultUnMuteAllRemoteVideoStreams;

- (int)subscribeRemoteVideoStreamByDefault;

- (int)unsubscribeRemoteVideoStreamByDefault;

- (void)muteAllRemoteVideoStreams;

- (void)unmuteAllRemoteVideoStreams;

- (void)setupLocalVideo:(KuaishouRtcEngineVideoCanvas* _Nullable)local;

- (void)setupRemoteVideo:(KuaishouRtcEngineVideoCanvas* _Nullable)remote;

- (void)setLocalRenderMode:(KuaishouRtcEngineVideoRenderMode)renderMode
                mirrorMode:(KuaishouRtcEngineVideoMirrorMode)mirrorMode;

- (void)setRemoteRenderMode:(NSString*)uid
                  channelId:(NSString*)channelId
                 renderMode:(KuaishouRtcEngineVideoRenderMode)renderMode
                 mirrorMode:(KuaishouRtcEngineVideoMirrorMode)mirrorMode;

- (void)setRemoteRenderMode:(KuaishouRtcEngineVideoRenderMode)renderMode
                 mirrorMode:(KuaishouRtcEngineVideoMirrorMode)mirrorMode;

- (void)startPreview;

- (void)stopPreview;

- (void)subscribeRemoteVideoStreams:(NSString*)channel uids:(NSArray*)uids;

- (void)unsubscribeRemoteVideoStreams:(NSString*)channel uids:(NSArray*)uids;


#pragma mark - Audio Routing Controller

- (int)setDefaultAudioRouteToSpeakerphone:(BOOL)defaultToSpeaker;

- (int)setEnableSpeakerphone:(BOOL)enableSpeaker;

- (BOOL)isSpeakerphoneEnabled;


#pragma mark - In Ear Monitor

- (int)enableInEarMonitoring;

- (int)disableInEarMonitoring;

- (int)setInEarMonitoringVolume:(NSInteger)volume;


#pragma mark - Audio Sound Effect

// set the local voice change option
- (void)setAudioEffectPreset:(KuaishouRtcEngineVoiceEffectOption)voiceChanger;

// set the preset local voice reverberation effect
- (void)setLocalVoiceReverbPreset:(KuaishouRtcEngineReverbLevel)reverbPreset;


#pragma mark - Music File Playback and Mixing

// start audio mixing
- (int)startAudioMixing:(NSArray*)urlList replace:(BOOL)replace cycle:(NSInteger)cycle progressIntervalMs:(int)progressIntervalMs destChannel:(KuaishouRtcEngineDestChannel)destChannel;

// stop audio mixing
- (int)stopAudioMixing;

// pause audio mixing
- (int)pauseAudioMixing;

// resume audio mixing
- (int)resumeAudioMixing;

/**
 * adjust the volume of audio mixing
 * @param volume audio mixing volume. The value ranges between 0 and 100 (default).
 * @return * 0: Success. < 0: Failure.
 */
- (int)adjustAudioMixingVolume:(NSInteger)volume;

/**
 * adjust the volume of audio mixing for local playback.
 * @param volume audio mixing volume for local playback. The value ranges between 0 and 100 (default).
 * @return * 0: Success. < 0: Failure.
 */
- (int)adjustAudioMixingPlayoutVolume:(NSInteger)volume;

/** Adjusts the volume of audio mixing for publishing (sending to other users).
 * @param volume Audio mixing volume for publishing. The value ranges between 0 and 100 (default).
 * @return * 0: Success. < 0: Failure.
 */
- (int)adjustAudioMixingPublishVolume:(NSInteger)volume;

// mute audio mixing
- (void)muteAudioMixing;

// unmute audio mixing
- (void)unmuteAudioMixing;

// get the audio mixing volume for local playback.
- (int)getAudioMixingPlayoutVolume;

// get the audio mixing volume for publishing.
- (int)getAudioMixingPublishVolume;

// set the playback position of the audio mixing file (the default plays from the beginning)
- (int)setAudioMixingPosition:(NSInteger)pos;

// set audio mixing pitch
- (int)setAudioMixingPitch:(NSInteger)pitch;

// index = 0 -> urlList[0], index = 1 -> urlList[1]
- (BOOL)updateAudioMixingLocalIndex:(int)localIndex remoteIndex:(int)remoteIndex;

// Retrieves the duration (ms) of audio mixing.
- (int)getAudioMixingDuration;

// Retrieves the playback position (ms) of the audio mixing file
- (int)getAudioMixingCurrentPosition;


#pragma mark - Audio Effect File Playback

- (int)playEffect:(NSString* _Nullable)fileName
        loopCount:(int)loopCount
          publish:(BOOL)publish
      destChannel:(KuaishouRtcEngineDestChannel)destChannel;

- (int)pauseEffect:(NSString* _Nullable)fileName;

- (int)resumeEffect:(NSString* _Nullable)fileName;

- (int)stopEffect:(NSString* _Nullable)fileName;

- (int)pauseAllEffects;

- (int)resumeAllEffects;

- (int)stopAllEffects;

- (int)preloadEffect:(NSString* _Nullable)fileName;

- (int)unloadEffect:(NSString* _Nullable)fileName;

- (void)unloadAllEffects;

- (double)getEffectsVolume;

- (int)setEffectsVolume:(double)volume;

- (int)muteEffects;

- (int)unmuteEffects;

- (int)setVolumeOfEffect:(NSString* _Nullable)fileName withVolume:(double)volume;


#pragma mark - Audio Recorder

/**
 * Start audio recording.
 * @param onAudio audio record callback function.
 */
- (void)startAudioRecording:(void(^)(const uint8_t* data, uint32_t size, int32_t energy))onAudio;

- (int)startAudioRecordingWithFilePath:(NSString* _Nonnull)filePath;

/**
 * Stop audio recording.
 */
- (int)stopAudioRecording;

#pragma mark - Miscellaneous Audio Control

/**
 * Enable Headphone Monitor
 * @param enable If YES, enable monitor.
 * @return if headphone is connected and enable monitor successful.
 */
- (BOOL)enableHeadphoneMonitor:(BOOL)enable;


#pragma mark - Video Recorder

- (void)startVideoRecording:(NSString*)filePath;

- (void)stopVideoRecording;

- (void)pauseVideoRecording;

- (void)resumeVideoRecording;



#pragma mark - Network-related Test

- (int)enableLastmileTest;

- (int)disableLastmileTest;


#pragma mark - External Audio Data

// enable the external audio source
- (void)enableExternalRawAudioSource;

// disable the external audio source
- (void)disableExternalRawAudioSource;

// push the external raw audio frame data
- (BOOL)pushExternalRawAudioFrame:(KuaishouRtcEngineAudioFrame* _Nonnull)frame;

// push the external raw audio data in CMSampleBufferRef
- (BOOL)pushExternalAudioFrameSampleBuffer:(CMSampleBufferRef)sampleBuffer;


#pragma mark - External Video Data

- (void)setExternalRawVideoSource:(BOOL)enable useTexture:(BOOL)useTexture;

- (BOOL)pushExternalRawVideoFrame:(KuaishouRtcEngineVideoFrame*)frame;


#pragma mark - Raw Audio Data

- (BOOL)setAudioFrameDelegate:(id<KuaishouRtcEngineAudioFrameDelegate>)delegate;

- (int)setRecordingAudioFrameParametersWithSampleRate:(NSInteger)sampleRate
                                              channel:(NSInteger)channel
                                                 mode:(KuaishouRtcEngineRawAudioOperationMode)mode
                                       samplesPerCall:(NSInteger)samplesPerCall;

- (int)setPlaybackAudioFrameParametersWithSampleRate:(NSInteger)sampleRate
                                             channel:(NSInteger)channel
                                                mode:(KuaishouRtcEngineRawAudioOperationMode)mode
                                      samplesPerCall:(NSInteger)samplesPerCall;

- (int)setMixedAudioFrameParametersWithSampleRate:(NSInteger)sampleRate
                                   samplesPerCall:(NSInteger)samplesPerCall;


#pragma mark - Watermark

/**
 * Draw logo onto video image.
 * @param logo logo image data with rgba format.
 */
- (void)addVideoWatermark:(KWAryaVideoWatermark*)logo;

/**
 * Draw logo onto video image.
 */
- (void)clearVideoWatermarks;


#pragma mark - Dual-stream Mode

- (int)enableDualStreamMode:(NSString*)channel;

- (int)disableDualStreamMode:(NSString*)channel;

- (int)setRemoteVideoStreamType:(NSString*)channel uid:(NSString*)uid streamType:(KuaishouRtcRemoteVideoStreamType)streamType;

- (int)setRemoteDefaultVideoStreamType:(NSString*)channel streamType:(KuaishouRtcRemoteVideoStreamType)streamType;


#pragma mark - Inject an Online Media Stream

/**
 * Start file loop streaming.
 * @param urlList stream source url list
 * @param config file stream config
 * @param channel channel
 * @return YES succeed or NO fail.
 */
- (BOOL)startFileStream:(NSArray*)urlList config:(KuaishouRtcEngineFileStreamingConfig*)config channel:(NSString*)channel;

/**
 * Stop file streaming.
 */
- (void)stopFileStream:(NSString*)channel;

/**
 * Pause file streaming
 */
- (void)pauseFileStream:(NSString*)channel;

/**
 * Resume file streaming
 */
- (void)resumeFileStream:(NSString*)channel;

/**
 * Seek file streaming
 */
- (void)seekFileStreamToMs:(int64_t)timeMs channel:(NSString*)channel;


#pragma mark - Live Transcoding

- (int)setLiveTranscoding:(NSString*)channelId andParam:(KuaishouRtcEngineLiveTranscoding*)transcoding;

- (int)stopLiveTranscoding:(NSString*)channelId;

- (int)addPublishStreamUrl:(NSString*)channelId andUrl:(NSString*)url;

- (int)removePublishStreamUrl:(NSString*)channelId andUrl:(NSString*)url;


#pragma mark - Data Stream

- (void)sendStreamMessage:(const uint8_t*)data len:(size_t)len;


#pragma mark - Miscellaneous Video Control

// Input a frame to be repeatedly processed to replace video.
- (int)replaceVideoFrame:(BOOL)enable
              videoframe:(KuaishouRtcEngineVideoFrame*)videoframe
             destChannel:(KuaishouRtcEngineDestChannel)destChannel;


#pragma mark - Camera Control

- (int)switchCamera;


#pragma mark - Game Voice

- (int)setAudioTeamId:(uint32_t)teamId;

- (int)setAudioTunnel:(KuaishouRtcEngineAudioTunnel)audioTunnel;

- (int)setAudioRecvRange:(uint32_t)range;

- (int)updateSelfPosition:(int32_t[_Nonnull 3])position
  axisForward:(float[_Nonnull 3])axisForward
    axisRight:(float[_Nonnull 3])axisRight
       axisUp:(float[_Nonnull 3])axisUp;

- (int)enableRangeAudio:(KuaishouRtcEngineAudioTunnel)audioTunnel;

- (int)disableRangeAudio:(KuaishouRtcEngineAudioTunnel)audioTunnel;

- (int)enableSpatializer:(KuaishouRtcEngineAudioTunnel)audioTunnel;

- (int)disableSpatializer:(KuaishouRtcEngineAudioTunnel)audioTunnel;

- (int)setHrtfModelPath:(NSString*)modelPath;

- (int)enableAttenuation:(KuaishouRtcEngineAudioTunnel)audioTunnel;

- (int)disableAttenuation:(KuaishouRtcEngineAudioTunnel)audioTunnel;

- (void)enableHrtfMode;

- (void)disableHrftMode;


#pragma mark - Layout Manager
- (NSMutableArray*)getParticipantMediaInfo:(NSString*)callId;

- (void)setVideoLayoutScheme:(NSString*)scheme;

- (NSMutableArray*)getVideoLayout:(NSArray*)mediaInfo;

- (void)requestVideoForParticipants:(NSString*)callId
                   participantsInfo:(nullable NSArray*)info
                            reqMode:(KuaishouRtcEngineVideoReqMode)reqMode;


#pragma mark - Miscellaneous Methods

/** Retrieves the SDK version.

 This method returns the string of the version number.

 @return The version of the current SDK in the string format. For example, 2.3.0
 */
+ (NSString* _Nonnull)getSdkVersion;

+ (int)setLogLevel:(KuaishouRtcEngineLogLevel)level;

+ (int)setLogFile:(NSString* _Nonnull)filePath;

+ (int)setLogFileSize:(NSUInteger)fileSizeInKBytes;

+ (int)setLogFileNum:(NSUInteger)fileNum;

+ (int)setLogCb:(void(^)(NSString*))cb;

/** Sets and retrieves the SDK delegate.
  The SDK uses the delegate to inform the app on engine runtime events. All methods defined in the delegate are optional implementation methods.
*/
@property(nonatomic, weak) id<KuaishouRtcEngineDelegate> _Nullable delegate;


@end

NS_ASSUME_NONNULL_END
