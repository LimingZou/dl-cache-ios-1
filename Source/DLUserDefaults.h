//
//  DLUserDefaults.h
//  DLCache
//
//  Created by limingzou on 2017/5/18.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import "DLCacheProtocol.h"

#pragma mark -

#define AS_USERDEFAULT( __name )	AS_STATIC_PROPERTY( __name )
#define DEF_USERDEFAULT( __name )	DEF_STATIC_PROPERTY3( __name, @"userdefault", [self description] )

#pragma mark -

@interface DLUserDefaults : NSObject<DLCacheProtocol>

AS_SINGLETON( DLUserDefaults )

@end
