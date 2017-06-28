//
//  NSObject+DLAssociated.h
//  DLFoundation
//
//  Created by limingzou on 2017/6/12.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>

@class NSString;
typedef objc_AssociationPolicy DLAssociationPolicy;
enum {
    DLAssociationPolicyAssign = OBJC_ASSOCIATION_ASSIGN,
    DLAssociationPolicyRetainNonatomic = OBJC_ASSOCIATION_RETAIN_NONATOMIC,
    DLAssociationPolicyCopyNonatomic = OBJC_ASSOCIATION_COPY_NONATOMIC,
    DLAssociationPolicyRetain = OBJC_ASSOCIATION_RETAIN,
    DLAssociationPolicyCopy = OBJC_ASSOCIATION_COPY
};

@interface NSObject (DLAssociated)
-(id)associatedValueForKey:(NSString *)aKey;
-(void)associateValue:(id)aValue withKey:(NSString *)aKey;
-(void)removeAssociatedValueForKey:(NSString *)aKey;
-(void)associateValue:(id)aValue withKey:(NSString *)aKey policy:(DLAssociationPolicy)aPolicy;
@end
