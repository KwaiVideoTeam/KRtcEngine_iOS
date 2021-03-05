#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol KuaishouRtcEngineAudioFrameDelegate <NSObject>
@optional

/**
 * Get Audio Record Frame
 */
- (BOOL)onRecordAudioFrame:(KuaishouRtcEngineAudioFrame*)frame;

/**
 * Get Audio Playback Frame
 */
- (BOOL)onPlaybackAudioFrame:(KuaishouRtcEngineAudioFrame*)frame;

/**
 * Get Audio Mixed Frame
 */
- (BOOL)onMixedAudioFrame:(KuaishouRtcEngineAudioFrame*)frame;

@end

NS_ASSUME_NONNULL_END
