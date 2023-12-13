// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
// Autogenerated from Pigeon (v10.1.6), do not edit directly.
// See also: https://pub.dev/packages/pigeon

#ifndef PIGEON_MESSAGES_G_H_
#define PIGEON_MESSAGES_G_H_
#include <flutter/binary_messenger.h>
#include <flutter/encodable_value.h>
#include <flutter/standard_message_codec.h>

#include <map>
#include <optional>
#include <string>
#include <utility>

namespace url_launcher_linux {


// Generated class from Pigeon.

class FlutterError {
 public:
  explicit FlutterError(std::string  code)
    : code_(std::move(code)) {}
  explicit FlutterError(std::string  code, std::string  message)
    : code_(std::move(code)), message_(std::move(message)) {}
  explicit FlutterError(std::string  code, std::string  message, flutter::EncodableValue  details)
    : code_(std::move(code)), message_(std::move(message)), details_(std::move(details)) {}

  const std::string& code() const { return code_; }
  const std::string& message() const { return message_; }
  const flutter::EncodableValue& details() const { return details_; }

 private:
  std::string code_;
  std::string message_;
  flutter::EncodableValue details_;
};

template<class T> class ErrorOr {
 public:
  ErrorOr(const T& rhs) : v_(rhs) {}
  ErrorOr(const T&& rhs) : v_(std::move(rhs)) {}
  ErrorOr(const FlutterError& rhs) : v_(rhs) {}
  ErrorOr(const FlutterError&& rhs) : v_(rhs) {}

  bool has_error() const { return std::holds_alternative<FlutterError>(v_); }
  const T& value() const { return std::get<T>(v_); };
  const FlutterError& error() const { return std::get<FlutterError>(v_); };

 private:
  friend class UrlLauncherApi;
  ErrorOr() = default;
  T TakeValue() && { return std::get<T>(std::move(v_)); }

  std::variant<T, FlutterError> v_;
};

// Generated interface from Pigeon that represents a handler of messages from Flutter.
class UrlLauncherApi {
 public:
  UrlLauncherApi(const UrlLauncherApi&) = delete;
  UrlLauncherApi& operator=(const UrlLauncherApi&) = delete;
  virtual ~UrlLauncherApi() = default;
  virtual ErrorOr<bool> CanLaunchUrl(const std::string& url) = 0;
  virtual std::optional<FlutterError> LaunchUrl(const std::string& url) = 0;

  // The codec used by UrlLauncherApi.
  static const flutter::StandardMessageCodec& GetCodec();
  // Sets up an instance of `UrlLauncherApi` to handle messages through the `binary_messenger`.
  static void SetUp(
    flutter::BinaryMessenger* binary_messenger,
    UrlLauncherApi* api);
  static flutter::EncodableValue WrapError(std::string_view error_message);
  static flutter::EncodableValue WrapError(const FlutterError& error);

 protected:
  UrlLauncherApi() = default;

};
}  // namespace url_launcher_linux
#endif  // PIGEON_MESSAGES_G_H_
