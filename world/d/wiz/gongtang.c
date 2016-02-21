// Room: /d/wiz/gongtang.c

inherit ROOM;

void create()
{
	set("short", "公堂");
	set("long", @LONG

开封府大堂。这里威武堂皇，大堂两侧站着两列手持红木棍的衙
役，一个个膀大腰粗，满脸横肉。正面高悬一匾：公正无私。匾
下案后定坐一位黑脸官员，一双眼睛严厉无比，直似要看到你心
里去了。你不由得双腿发软，浑身嗦嗦直抖。
LONG
	);
	
	set("no_clean_up", 0);
	set("objects", ([
		__DIR__"npc/baogong":1 ]) );

	setup();
	
}


