require "json"

package = JSON.parse(File.read(File.join(__dir__, "package.json")))

Pod::Spec.new do |s|
  s.name         = "Recyclerlist"
  s.version      = package["version"]
  s.summary      = package["description"]
  s.homepage     = package["homepage"]
  s.license      = package["license"]
  s.authors      = package["author"]

  s.platforms    = { :ios => min_ios_version_supported }
  s.source       = { :git => "https://github.com/pythonsst/react-native-recyclerlist.git", :tag => "#{s.version}" }

  s.source_files = [
    "ios/**/*.{swift}",
    "ios/**/*.{m,mm}",
    "cpp/**/*.{hpp,cpp}",
  ]

  s.dependency 'React-jsi'
  s.dependency 'React-callinvoker'
  s.static_framework = true

  # s.pod_target_xcconfig = {
  #   'CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES' => 'YES'
  # }

  s.pod_target_xcconfig = {
  'HEADER_SEARCH_PATHS' => '"$(PODS_ROOT)/Headers/Public/ReactCommon" "$(PODS_ROOT)/Headers/Public/ReactCommon/react/renderer"',
  'CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES' => 'YES'
 }

  load 'nitrogen/generated/ios/Recyclerlist+autolinking.rb'
  add_nitrogen_files(s)

  install_modules_dependencies(s)
end
