/*! @file OIDTokenResponse.h
    @brief AppAuth iOS SDK
    @copyright
        Copyright 2015 Google Inc. All Rights Reserved.
    @copydetails
        Licensed under the Apache License, Version 2.0 (the "License");
        you may not use this file except in compliance with the License.
        You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

        Unless required by applicable law or agreed to in writing, software
        distributed under the License is distributed on an "AS IS" BASIS,
        WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
        See the License for the specific language governing permissions and
        limitations under the License.
 */

#import <Foundation/Foundation.h>

@class OIDTokenRequest;

NS_ASSUME_NONNULL_BEGIN

/*! @brief Represents the response to an token request.
    @see https://tools.ietf.org/html/rfc6749#section-3.2
    @see https://tools.ietf.org/html/rfc6749#section-4.1.3
 */
@interface OIDTokenResponse : NSObject <NSCopying, NSSecureCoding> {
  // property variables
  OIDTokenRequest *_request;
  NSString *_accessToken;
  NSDate *_accessTokenExpirationDate;
  NSString *_tokenType;
  NSString *_idToken;
  NSString *_refreshToken;
  NSString *_scope;
  NSDictionary<NSString *, NSObject<NSCopying> *> *_additionalParameters;
}

/*! @brief The request which was serviced.
 */
@property(nonatomic, readonly) OIDTokenRequest *request;

/*! @brief The access token generated by the authorization server.
    @discussion Set when the response_type requested includes 'token'.
    @remarks access_token
    @see http://openid.net/specs/openid-connect-core-1_0.html#ImplicitAuthResponse
 */
@property(nonatomic, readonly, nullable) NSString *accessToken;

/*! @brief The approximate expiration date & time of the access token.
    @remarks expires_in
    @seealso OIDTokenResponse.accessToken
    @see http://openid.net/specs/openid-connect-core-1_0.html#ImplicitAuthResponse
 */
@property(nonatomic, readonly, nullable) NSDate *accessTokenExpirationDate;

/*! @brief Typically "Bearer" when present. Otherwise, another token_type value that the Client has
        negotiated with the Authorization Server.
    @discussion Set when the response_type requested includes 'token'.
    @remarks token_type
    @see http://openid.net/specs/openid-connect-core-1_0.html#ImplicitAuthResponse
 */
@property(nonatomic, readonly, nullable) NSString *tokenType;

/*! @brief ID Token value associated with the authenticated session.
    @discussion Set when the response_type requested includes 'id_token'.
    @remarks id_token
    @see http://openid.net/specs/openid-connect-core-1_0.html#IDToken
    @see http://openid.net/specs/openid-connect-core-1_0.html#ImplicitAuthResponse
 */
@property(nonatomic, readonly, nullable) NSString *idToken;

/*! @brief The refresh token, which can be used to obtain new access tokens using the same
        authorization grant
    @remarks refresh_token
    @see https://tools.ietf.org/html/rfc6749#section-5.1
 */
@property(nonatomic, readonly, nullable) NSString *refreshToken;

/*! @brief The scope of the access token. OPTIONAL, if identical to the scopes requested, otherwise,
        REQUIRED.
    @remarks scope
    @see https://tools.ietf.org/html/rfc6749#section-5.1
 */
@property(nonatomic, readonly, nullable) NSString *scope;

/*! @brief Additional parameters returned from the token server.
 */
@property(nonatomic, readonly, nullable)
    NSDictionary<NSString *, NSObject<NSCopying> *> *additionalParameters;

/*! @internal
    @brief Unavailable. Please use initWithParameters:.
 */
- (instancetype)init NS_UNAVAILABLE;

/*! @brief Designated initializer.
    @param request The serviced request.
    @param parameters The decoded parameters returned from the Authorization Server.
    @remarks Known parameters are extracted from the @c parameters parameter and the normative
        properties are populated. Non-normative parameters are placed in the
        @c #additionalParameters dictionary.
 */
- (instancetype)initWithRequest:(OIDTokenRequest *)request
                     parameters:(NSDictionary<NSString *, NSObject<NSCopying> *> *)parameters
                     NS_DESIGNATED_INITIALIZER;

- (NSDictionary<NSString *, NSObject<NSCopying> *> *) getRawJSONDict;

@end

NS_ASSUME_NONNULL_END
