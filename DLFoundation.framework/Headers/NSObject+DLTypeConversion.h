//
//  NSObject+DLTypeConversion.h
//  DLFoundation
//
//  Created by limingzou on 2017/5/12.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import <Foundation/Foundation.h>

#define XINT(value)    ([value asInteger])
#define XFLOAT(value)  ([value asFloat])
#define XBOOL(value)   ([value asBool])
#define XSTRING(value) ([value asNSString])
#define XNUMBER(value) ([value asNSNumber])

#define $I(value) XINT(value)
#define $F(value) XFLOAT(value)
#define $B(value) XBOOL(value)
#define $S(value) XSTRING(value)
#define $N(value) XNUMBER(value)

@interface NSObject (DLTypeConversion)
- (NSInteger)asInteger;
- (float)asFloat;
- (BOOL)asBool;

- (NSNumber *)asNSNumber;
- (NSString *)asNSString;
- (NSDate *)asNSDate;
- (NSData *)asNSData;
- (NSArray *)asNSArray;
- (NSArray *)asNSArrayWithClass:(Class)clazz;
- (NSMutableArray *)asNSMutableArray;
- (NSMutableArray *)asNSMutableArrayWithClass:(Class)clazz;
- (NSDictionary *)asNSDictionary;
- (NSMutableDictionary *)asNSMutableDictionary;
@end
