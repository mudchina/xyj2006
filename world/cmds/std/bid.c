#include <dbase.h>
#define MARKETPLACE "/d/city/paimaiwu"
#define SELLOR "/d/wiz/npc/paimaishi"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object room,obj;
	int argg;
	int invisibility_buyer;
	int number;
	int value;

	seteuid( geteuid(me) );

	if( me->is_busy() ) return notify_fail("你现在没有空！\n");
	if( !arg )
		return notify_fail("指令格式：bid <数量>\n");

	if( sscanf(arg, "-i %s", arg) ) invisibility_buyer = 1;

	if( !arg )
		return notify_fail("指令格式：bid <数量>\n");

	sscanf(arg,"%d for %d",argg,number);

//拍卖师放置的路径
	if( !(room=find_object(MARKETPLACE)) )
		room= clone_object(MARKETPLACE);
	
	if( !(obj=present("paimai shi",room)) )
	{
		obj=new(SELLOR);
		obj->move(MARKETPLACE);
		return notify_fail("拍卖师现在刚来，但没有在拍卖。\n");
	}

	else
	{
		if( !(obj->query("on_paimai")) ) 
			return notify_fail("现在没有在拍卖。\n");
	}

	if( me->query_condition("auction_forbindden") )
		return notify_fail("你目前还不能参与拍卖活动。\n");
	if( invisibility_buyer)
		me->set_temp("invisibility_buyer",1);
	else
		me->set_temp("invisibility_buyer",0);
    
	if(!number)
		number = obj->query("number");

	if(number>obj->query("number"))
		return notify_fail("目前还没有开始这件物品拍卖。\n");
//    if(obj->query("ipaimai/"+sprintf("%d",number))=="paimai shi")
	if(number<obj->query("number"))
	   return notify_fail("这样东西的拍卖已经结束了。\n");
	
	value = obj->query("vpaimai/"+sprintf("%d",number));

	if( argg <= value*21/20 )
	{
		tell_object(me,"你出价太低。\n");
		return notify_fail("现在是"+chinese_number(value)+"两银子！\n");
	}
    if(argg < 0 || argg > 1000000)
		return notify_fail("你出的价格是非法的。\n");
	if( argg*105 > me->query("balance") )
		return notify_fail("你没有这么多的存款！\n");
	obj->report_paimai(me,argg,number);
	tell_object(me,"你出价"+chinese_number(argg)+"两银子！\n");

	me->start_busy(2);

	return 1;

}

int help(object me)
{
   write( @HELP
指令格式: bid <数量> 

这一指令让你可以参与投标，单位为 两银子。
HELP
   );
   return 1;
}
 