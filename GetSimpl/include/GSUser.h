//
//  GSUser.h
//  GetSimpl
//
//  Created by Alok Jha on 15/02/16.
//  Copyright © 2016 Simpl. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GSUser : NSObject

/// Convenience initializer of GSUser
///
/// \param phoneNumber Phone number of the user
///
/// \param email Email id of the user
- (nonnull instancetype)initWithPhoneNumber:(NSString * __nonnull)phoneNumber email:(NSString * __nonnull)email;

/// Another Convenience initializer of GSUser
///
/// \param hashedPhoneNumber The hashed representation of phone number of the user
///
-(nonnull instancetype)initWithHashedPhoneNumber:(NSString * __nonnull)hashedPhoneNumber;


/// Email id of the user
@property (nonatomic, copy) NSString * __nullable email;

/// Phone number of the user.
@property (nonatomic, copy) NSString * __nullable phoneNumber;

/// Hashed value of phone number of the user if merchant does not want to share data upfront.
@property (nonatomic, copy) NSString * __nullable hashedPhoneNumber;

/// Extra properties of GSUser to be set as Key-Value pairs. Example of some keys are : transaction_amount_in_paise, wallet_balance,failed_transaction_bank_name, user_location, theatre_location,member_since, signed_in . If merchant is using hashedPhoneNumber to check for pre-approval then the above keys will be used for realtime approval of users if merchant has realtime configuration enabled on server side.
@property (nonatomic, copy) NSDictionary<NSString *, id> * __nullable extraParams;
@end
