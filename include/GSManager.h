//
//  GSManager.h
//  GetSimpl
//
//  Created by Alok Jha on 15/02/16.
//  Copyright © 2016 Simpl. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GSTransaction.h"


@interface GSManager : NSObject

/// Initilaze the SDK with your merchantID .This should happen typically in your applications didFinishLaunchingWithOptions method.
///
/// \param merchantID Your merchantID
+ (void)initializeWithMerchantID:(NSString * __nonnull)merchantID;

/// Toggle between sandbox or production environment for SDK.
///
/// \param enable Boolean variable to toggle
+ (void)enableSandBoxEnvironment:(BOOL)enable;

/// Shared instance for GSManager. Use this instance to make all subsequent calls.
+ (GSManager * __nonnull)sharedManager;

/// MerchantId for the merchant
@property (nonatomic, readonly, copy) NSString * __nullable merchantID;

/// Boolean to check whether sandBoxEnvironment is enabled or not
@property (nonatomic, readonly) BOOL isSandBoxEnvironmentEnabled;

/// Checks for approval status of a User
///
/// \param user A GSUser object encapsulating the user data
///
/// \param completion Completion block for the response with following arguments in
/// order :<ul><li>Bool approved : If GSUser is pre-approved or not</li><li>Bool isFirstTransactionOfUser : If user has already done transactions
/// previously or not</li><li>String/NSString buttonText : The text to display on Simpl button. If GSUser is pre-approved,this will contain a value specific to merchant with default value of "Buy Now, Pay Later". Will be nil if GSUser is not pre-approved.</li><li>NSError error : Error if any</li></ul>
- (void)checkApprovalForUser:(GSUser * __nonnull)user onCompletion:(void (^ __nonnull)(BOOL approved, BOOL isFirstTransactionOfUser, NSString * __nullable buttonText, NSError * __nullable error))completion;

/// Authorizes and returns appropriate response for a transaction
///
/// On successful transaction jsonResponse will contain transaction_token key which is to be sent to Merchant server with
/// cart details within 1 Hr of doing the transaction.
///
/// \param transaction A GSTransaction object encapsulating GSUser and transaction amount
///
/// \param completion Completion block for the response with following arguments in
/// order :<ul><li>NSDictionary jsonResponse : URL response in json format</li><li>NSError error : Error if any</li></ul>
- (void)authorizeTransaction:(GSTransaction * __nonnull)transaction onCompletion:(void (^ __nonnull)(NSDictionary * __nullable jsonResponse, NSError * __nullable error))completion;


@end
