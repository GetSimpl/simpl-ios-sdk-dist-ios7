Pod::Spec.new do |s|
  s.name         = "GetSimpl-iOS"
  s.version      = "1.8.7"
  s.summary      = "GetSimpl iOS SDK Static Library"
  s.homepage     = "https://github.com/GetSimpl/simpl-ios-sdk-dist-ios7"
  s.source = {:git => 'https://github.com/GetSimpl/simpl-ios-sdk-dist-ios7.git',:tag => "v#{s.version}"}
  s.license = {:type => 'Commercial' , :file => 'License'}
  s.platform = :ios, '7.0'
  s.author       = { "Simpl" => "devarajan@getsimpl.com" }
  s.source_files = "include/*.h"
  s.public_header_files = "include/*.h"
  s.preserve_paths = "libGetSimpl.a"
  s.ios.vendored_library = "libGetSimpl.a"
  s.requires_arc = true
  s.frameworks = 'Security','SystemConfiguration' , 'CoreLocation'
end
