//
//  DLPerformance.h
//  DLFoundation
//
//  Created by limingzou on 2017/5/12.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DLFoundation/DLSingleton.h>

#pragma mark -

#define PERF_TAG( __X )				[NSString stringWithFormat:@"%s %s", __PRETTY_FUNCTION__, __X]
#define PERF_TAG1( __X )			[NSString stringWithFormat:@"enter - %s %s", __PRETTY_FUNCTION__, __X]
#define PERF_TAG2( __X )			[NSString stringWithFormat:@"leave - %s %s", __PRETTY_FUNCTION__, __X]

#define	PERF_MARK( __X )			[[DLPerformance sharedInstance] markTag:PERF_TAG(#__X)];
#define	PERF_TIME( __X1, __X2 )		[[DLPerformance sharedInstance] betweenTag:PERF_TAG(#__X1) andTag:PERF_TAG(#__X2)]

#define PERF_ENTER					[[DLPerformance sharedInstance] markTag:PERF_TAG1("")];
#define PERF_LEAVE \
[[DLPerformance sharedInstance] markTag:PERF_TAG2("")]; \
[[DLPerformance sharedInstance] recordName:PERF_TAG("") \
andTime:[[DLPerformance sharedInstance] betweenTag:PERF_TAG1("") andTag:PERF_TAG2("")]];

#define PERF_ENTER_( __X )			[[DLPerformance sharedInstance] markTag:PERF_TAG1(#__X)];
#define PERF_LEAVE_( __X ) \
[[DLPerformance sharedInstance] markTag:PERF_TAG2(#__X)]; \
[[DLPerformance sharedInstance] recordName:PERF_TAG(#__X) \
andTime:[[DLPerformance sharedInstance] betweenTag:PERF_TAG1(#__X) andTag:PERF_TAG2(#__X)]];

#pragma mark -

@interface DLPerformanceRecord : NSObject
@property (nonatomic, retain) NSString *		name;
@property (nonatomic, assign) NSTimeInterval	time;
@end

#pragma mark -

@interface DLPerformance : NSObject

AS_SINGLETON( DLPerformance );

@property (nonatomic, readonly) NSArray *		records;
@property (nonatomic, assign) NSTimeInterval	valve;

- (double)timestamp;

- (double)markTag:(NSString *)tag;
- (double)betweenTag:(NSString *)tag1 andTag:(NSString *)tag2;
- (double)betweenTag:(NSString *)tag1 andTag:(NSString *)tag2 shouldRemove:(BOOL)remove;

- (void)watchClass:(Class)clazz;
- (void)watchClass:(Class)clazz andSelector:(SEL)selector;

- (void)recordName:(NSString *)name andTime:(NSTimeInterval)time;

@end

