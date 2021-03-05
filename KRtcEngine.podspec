#
#  Be sure to run `pod spec lint KRtcEngine_iOS.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  spec.name         = "KRtcEngine_iOS"
  spec.version      = "0.0.1"
  spec.summary      = "Kuaishou RtcEngine iOS"

  spec.description  = <<-DESC
              LiveStream and RTC
                   DESC

  spec.homepage     = "https://github.com/KwaiVideoTeam/KRtcEngine_iOS"

  spec.license      = { :type => "BSD", :text => <<-LICENSE
                          Copyright 2020 www.kuaishou.com All rights reserved.
                        LICENSE
                      }

  spec.author       = { "Kuaishou Video Team" => "video@kuaishou.com" }
  spec.platform     = :ios, "9.0"

  spec.source       = { :git => "https://github.com/KwaiVideoTeam/KRtcEngine_iOS.git", :tag => "#{spec.version}" }

  spec.ios.vendored_frameworks = 'KRtcEngine.framework'
  # spec.public_header_files = "Classes/**/*.h"

  spec.frameworks = "VideoToolbox", "AudioToolbox", "GLKit"

end
