#import "objtest.h"
#import <stdio.h>
int main()
{
	LYClass* mc=[[LYClass alloc] init:20];
	NSLog(@"Ready to NSLog\n");
	NSLog(@"m_Count is %d\n",mc.m_Count);
	NSLog(@"Finish NSLog\n");
	return 0;
}
