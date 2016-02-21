
inherit ITEM;   
int fail_to_push(object who);
int ok_to_push(object who);
        
void create()
{
        set_name("石桌",({"table"}));
        set_weight(5000000);
        if (clonep())
                set_default_object(__FILE__);
        else {  
                set("long","一张八角形的石桌，下边有不少划痕，似乎可以推动(push)。\n");
                set("unit", "张");
    }
 
        setup();
}
        
void init()     
{
        add_action("do_push", "push");
}       
        
                
int do_push(string arg)
{	object who=this_player();
                
        if( !arg || arg!="table")
                return notify_fail("你要推什么？\n");
                call_out("ok_to_push", 1, who);
		return 1;
}
int fail_to_push(object who)
{	
        if( !who || environment(who) != environment(this_object()) ) return 1;
        if( (int)who->query("kee") < 100
        ||      (int)who->query("force") < 100
        ||      (int)who->query_str() < 60 ) {

		message_vision("$N试着去推石桌，可石桌却象扎了根一般动也不动。\n",who);
                return 1;
        }
        who->receive_damage("kee", 80);
        who->add("force", -30);

	message_vision("$N试着去推石桌，石桌只是轻轻晃动了两下，又回到原位。\n",who);
        return 1;
}
int ok_to_push(object who)
{	
        if( !who || environment(who) !=environment(this_object()) ) return 1;
        if( (int)who->query("kee") <100
        ||      (int)who->query("force") < 100
        ||      (int)who->query_str() < 60 ) {
		call_out("fail_to_push", 2, who);
		return 1;
        }

	if( (int)this_object()->query("done") ) {
		call_out("fail_to_push", 2, who);
		return 1;
	}

      if( !who->query_temp("enter_position") ) {
		call_out("fail_to_push", 2, who);
		return 1;
	}
	if( (string)who->query_temp("enter_position")==(string)who->query_temp("heard_position")){
                call_out("succeed", 2, who);
		return 1;
        }
	if ( (string)who->query_temp("enter_position") =="乾" ) {
                call_out("qian", 2, who);
        	return 1;
	}
	if ( (string)who->query_temp("enter_position") =="坤" ) {
                call_out("kun", 2, who);
        	return 1;
	}
	if ( (string)who->query_temp("enter_position") =="艮" ) {
                call_out("gen", 2, who);
		return 1;
        }
	if ( (string)who->query_temp("enter_position") =="兑" ) {
                call_out("dui", 2, who);
		return 1;
        }
	if ( (string)who->query_temp("enter_position") =="震" ) {
                call_out("zhen", 2, who);
        	return 1;
	} 
	if ( (string)who->query_temp("enter_position") =="巽" ) {
                call_out("gong", 2, who);
        	return 1;
	}
	if ( (string)who->query_temp("enter_position") =="坎" ) {
                call_out("kan", 2, who);
        	return 1;
	}
	if ( (string)who->query_temp("enter_position") =="离" ) {
                call_out("li", 2, who);
		return 1;
        }
}
int succeed(object who)
{	object m;
        if( !who || environment(who) !=environment(this_object()) ) return 1;
	if( m = new("/d/qujing/bibotan/obj/xiazi") ){
	m->move(who);
	message_vision("$N使尽全身力气推开了石桌，露出个金光灿灿的匣子。\n", who);
	message_vision("$N伸手将匣子揽到了怀里。\n", who);
	}
	this_object()->set("done", 1);
	return 1;
}
int qian(object who)
{	int i;
	i=(int)who->query("max_kee")/5;
        if( !who || environment(who) !=environment(this_object()) ) return 1;

        message_vision("$N使出全身的力气去推那石桌，石桌摇了摇，小亭一角却掉了下来。\n",who);
        message_vision("\n小亭的一角歪歪的砸在$N的脑袋上，砸的$N头破血流。\n", who);
        if( (int)who->query_temp("push_time") > 3) {
                call_out("faint_him", 1, who);
        return 1;
	}
        who->receive_wound("kee", i);
	COMBAT_D->report_status(who);
        who->add_temp("push_time", 1);   
        return 1;
}
int kun(object who)
{	int i;
	i=(int)who->query("max_kee")/5;
        if( !who || environment(who) !=environment(this_object()) ) return 1;

        message_vision("$N使出全身的力气去推那石桌，脚下的地却忽然陷开一个大洞。\n",who);
        message_vision("\n$N一不小心陷了下去，又挣扎着爬了上来。\n", who);
        if( (int)who->query_temp("push_time") > 3) {
                call_out("faint_him", 0, who);
        return 1;
	}
        message_vision("\n$N身上被擦破好几处，一幅狼狈不堪的样子。\n", who);
        who->receive_wound("kee", i);
        COMBAT_D->report_status(who);  
        who->add("push_time", 1);   
        return 1;
}
int gen(object who)
{	int i;
	i=(int)who->query("max_kee")/5;
        if( !who || environment(who) !=environment(this_object()) ) return 1;

        message_vision("$N使出全身的力气去推那石桌，石桌推开后却露出一堆大石头。\n",who);
	message_vision("\n$N被滚下的石头埋了起来。\n",who);
        if( (int)who->query_temp("push_time") > 3) {
                call_out("faint_him", 0, who);
        return 1;
	}
        message_vision("\n$N从石堆从爬了出来，手脚都被砸破了。\n", who);
        who->receive_wound("kee", i);
        COMBAT_D->report_status(who);
        who->add("push_time", 1);   
        return 1;
}
int dui(object who)
{	int i;
	i=(int)who->query("max_sen")/5;
        if( !who || environment(who) !=environment(this_object()) ) return 1;

        message_vision("$N使出全身的力气去推那石桌，石桌下忽然现出一个泥潭来。\n",who);
        message_vision("\n$N一个不稳，掉到了泥潭中，溅起一滩稀泥。\n", who);
        if( (int)who->query_temp("push_time") > 3) {
                call_out("faint_him", 0, who);
        return 1;
	}
        message_vision("\n$N慢慢地从泥潭中爬了出来，看起来相当狼狈。\n", who);
        who->receive_wound("sen", i);
        COMBAT_D->report_sen_status(who);
        who->add_temp("push_time", 1);   
        return 1;
}
int zhen(object who)
{	int i;
	i= (int)who->query("max_sen")/5 ;
        if( !who || environment(who) !=environment(this_object()) ) return 1;

        message_vision("$N使出全身的力气去推那石桌，头上忽然炸起一声闷雷。\n",who);
        message_vision("\n雷声震的小亭上灰土直落，好象要塌了的样子。\n", who);
        if( (int)who->query_temp("push_time") > 3) {
                call_out("faint_him", 0, who);
        return 1;
	}
        message_vision("\n$N被震的晕头转向，瘫坐在地下。\n", who);
        who->receive_wound("sen", i);
        COMBAT_D->report_sen_status(who);
        who->add_temp("push_time", 1);   
        return 1;
}
int gong(object who)
{	int i;
        i= (int)who->query("max_sen")/5 ;
        if( !who || environment(who) !=environment(this_object()) ) return 1;

	message_vision("$N使出全身的力气去推那石桌，石桌竟被推开了，露出黑黝黝的一个洞口。\n",who);
        message_vision("\n洞口中忽然刮出一阵阴风，夹头夹脑的吹向$N！\n", who);
        if( (int)who->query_temp("push_time") > 3) {
                call_out("faint_him", 0, who);
        return 1;
	}
        message_vision("\n$N被吹的晕头转向，不知所措。\n", who);
        who->receive_wound("sen", i);
        COMBAT_D->report_sen_status(who);
        who->add_temp("push_time", 1);
	return 1;
}
int kan(object who)
{	int i;
        i= (int)who->query("max_kee")/5 ;
        if( !who || environment(who) !=environment(this_object()) ) return 1;

        message_vision("$N使出全身的力气去推那石桌，石桌竟被推开了，钻出两条冷龙来。\n",who);
        message_vision("\n冷龙口一张，对准$N喷出了两股奇寒无比的水柱。\n", who);
        if( (int)who->query_temp("push_time") > 3) {
                call_out("faint_him", 0, who);
        return 1;
	}
        message_vision("\n$N被水柱击中，浑身上下都湿透了，冻的直打哆嗦。\n", who);
        who->receive_wound("kee", i);
        COMBAT_D->report_status(who);
        who->add_temp("push_time", 1);   
        return 1;
}
int li(object who)
{	int i;
        i= (int)who->query("max_kee")/5 ;
        if( !who || environment(who) !=environment(this_object()) ) return 1;

        message_vision("$N使出全身的力气去推那石桌，石桌竟被推开了，钻出两条火龙来n",who);
        message_vision("\n火龙口一张，对准$N喷出了两股粉金融玉的火柱。\n", who);
        if( (int)who->query_temp("push_time") > 3) {
                call_out("faint_him", 0, who);
        return 1;
	}

        message_vision("\n$N被烧的遍体粼伤，惨不忍睹。\n", who);
        who->receive_wound("kee",i);
        COMBAT_D->report_status(who);
        who->add_temp("push_time", 1);   
        return 1;
}
int faint_him(object who)
{	who->delete_temp("push_time");
	who->unconcious();
	return 1;
}

