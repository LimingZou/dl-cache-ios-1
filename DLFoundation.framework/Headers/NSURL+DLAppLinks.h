//
//  NSURL+DLAppLinks.h
//  DLFoundation
//
//  Created by limingzou on 2017/5/23.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSURL (DLAppLinks)
- (BOOL)equal:(NSURL*)url;
+ (NSURL *)appStoreID:(NSString *)identifier;
+ (NSURL *)appStoreReviewID:(NSString *)identifier;
@end
