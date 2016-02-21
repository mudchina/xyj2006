//Cracked by Roath

#include <ansi.h> 
#include <room.h> 
#include <login.h> 
  
inherit ROOM; 
  
string look_sign(); 
  
void create() 
{ 
        set("short", "长 安 黑 市"); 
        set("long", @LONG 
这里是长安城集市。满街的店铺都挂着一团团、一簇簇的羊角风灯。 
一声接一声的叫卖声在各个街口、小巷深处此呼彼应，连绵不绝。集
市的 入口处，挂着一块牌子(sign)。 
LONG 
        ); 
  
        set("outdoors", "changan"); 
  
        set("item_desc", ([ 
                "sign": @TEXT 
在这里你可以做下面的事情。 
  
join        开始做生意 
  
TEXT 
        ]) ); 
  
        set("exits", ([ 
            "east" : "/d/city/beiyin1.c",
        ]) ); 
  
        set("no_fight", 1); 
        set("no_magic",1); 
  
/*
        set("objects", ([ 
               "/d/changan/npc/qianmian": 1, 
        ]) ); 
*/
  
        setup(); 
} 
  
void init() 
{ 
        add_action("do_join", "join"); 
        add_action("do_quit", "quit");
} 
  
int do_join(string arg) 
{ 
       string *name = ({ "私盐","水果","食品","陈酒","鲜花","草药","煤炭", 
                "古董","珠宝","玉器","字画","木材","竹器","武器","铁器","农具", 
                "马匹","布匹","瓷器","杂货", });
        object me; 
        string tempstr, namestr; 
  
        me = this_player(); 
  
        if(me->query_temp("working") == 1) 
                return notify_fail("你已经在贩卖当中了！\n"); 
  
//yudian prevent too many dummy
        if(me->query("combat_exp") < 100000) 
                return notify_fail("不务正业！还不把武功练好！\n"); 
        if(me->query("daoxing") < 100000) 
                return notify_fail("不务正业！还不把道行练好！\n"); 

        namestr = name[random(sizeof(name))]; 
        tempstr = "$N开始贩卖" + namestr + "....\n"; 
        message_vision(tempstr, me); 
  
        if( namestr == "私盐" ) { 
                tempstr = "官兵把$N捉了起来：“贩卖" + namestr + 
                        "？这可是砍头的罪名！”\n"; 
                message_vision(tempstr, me); 
                if( random(10) == 0 ) {         // 打入大牢 
                        me->set("startroom", START_ROOM ); 
                        me->move( __DIR__"dalao" ); 
                        set("name", "官府"); 
                        set("id", "guanfu"); 
                        set("channel_id","大唐告示");
                        CHANNEL_D->do_channel(this_object(), "chat", 
                                HIY+me->name() + "贩卖" + namestr + 
                                "，被打入大牢，等候秋后处斩！！！"NOR ); 
                } 
                else { 
                        if( random(20) == 0 ) { 
                                switch( random(9) ) { 
case 0: tempstr = "/d/city/recycle"; 
        break; 
case 1: tempstr = "/d/kaifeng/donghu"+(random(5)+1); 
        break; 
case 2: tempstr = "/d/qujing/dudi/shanlu" + ( random(10) + 1); 
        break; 
case 3: tempstr = "/d/qujing/wuzhuang/wzgmaze" + ( random(8) + 1); 
        break; 
case 4: tempstr = "/d/qujing/tianzhu/jiedao" + ( random(8) + 91); 
        break; 
case 5: tempstr = "/d/qujing/nuerguo/townc" + ( random(3) + 1); 
        break; 
case 6: tempstr = "/d/qujing/fengxian/jiedao" + ( random(14) + 1); 
        break; 
case 7: tempstr = "/d/qujing/yinwu/caopo" + ( random(5) + 1); 
        break; 
case 8: tempstr = "/d/sea/maze" + ( random(7)); 
        break; 
                                } 
                            
                                me->set("startroom", tempstr ); 
tempstr = "$N掏出厚厚一叠银票对官兵说：大爷行行好吧，我家还有八十岁的老娘呢....\n" 
        + "官兵将银票一把抢过，放入怀中，探了探头，见到左右无人，喝道：这么少！\n" 
        + "官兵一脚将$N踢到九霄云外：“叫你贩卖" + namestr + "！下回再捉往，砍头！” \n"; 
                                message_vision(tempstr, me); 
                               me->move( tempstr ); 
                        } 
                        else {                  
                                me->set("startroom", START_ROOM ); 
tempstr = "官兵一脚把$N踢了出来：“叫你贩卖" + namestr 
        + "！下回再捉往，砍头！”\n"; 
                                message_vision(tempstr, me); 
                               me->move( START_ROOM ); 
                        } 
                } 
                return 1; 
        } 
  
        me->set_temp("working", 1); 
        me->set_temp("no_quit",1);
        call_out( "compelete_join", 4+random(8), me ); 
        return 1; 
} 
  
private void compelete_join(object me) 
{ 
        object ob; 
        int i, n; 
  
        if (!me) return; 
        me->delete_temp("working"); 
        if( present(me) ) { 
                message_vision("$N开展生意，人虽然累坏了，但是收益不小。\n", me);  
                me->add("kee", -25); 
                me->add("sen", -25); 
                me->add("potential", (me->query("combat_exp") >= 15000) ? 
                        random(4) : 8+random(10) ); 
                me->add("daoxing", (me->query("combat_exp") >= 15000) ? 

                        random(6) : 8+random(8)); 
                n = random(10* me->query("kar")) / 30; 
                if (me->query("combat_exp")>=15000)  n=random(3);
                ob = new("/obj/money/silver"); 
                ob->set_amount(n+1); 
                ob->move(me); 
                tell_object(me, "你的潜能和道行增加了！\n"); 
                tell_object(me, sprintf("你赚到"HIW"%s"NOR"两银子。\n", chinese_number(n+1))); 
        } 
  
        return; 
}

int do_quit(object me)
{
        me = this_player();
	if(me->query_temp("working"))
	{
	write("生意还没做完，就想溜？\n");
	return 1;
         }
else return 0;
}
	
