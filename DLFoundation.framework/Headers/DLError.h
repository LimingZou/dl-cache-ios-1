//
//  DLError.h
//  DLFoundation
//
//  Created by limingzou on 2017/5/24.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DLError : NSObject

+ (BOOL)isNetworkError:(NSError *)error;

@end
