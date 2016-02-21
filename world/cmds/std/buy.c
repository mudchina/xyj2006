// buy.c
#define FAMILYD "/adm/daemons/familyd"
#define SHILI_D "/adm/daemons/shili"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string item, targ;
        object ob, owner;
        int price, afford;
        string fname,opfaname,faname=me->query("family/family_name");
        string* slist;

        if( this_player()->is_busy() )
                        return notify_fail("你现在正忙着呢。\n");

        if( !arg || sscanf(arg, "%s from %s", item, targ)!=2 )
                return notify_fail
("指令格式：buy <某物> from <某人>\n");

        if( !objectp(owner = present(targ, environment(me))) )
                return notify_fail("你要跟谁买东西？\n");

           if( userp(owner) ) {
                message_vision("$N想向$n购买「" + item + "」。\n", me, owner);
                notify_fail("对方好像不愿意跟你交易。\n");
                return 1;
        }
        
        if( (price = owner->buy_object(me, item)) == -1 ) return 1;
        if( price < 1 ) return 0;

        fname=file_name(environment(me));
        slist=explode(fname,"/");
        opfaname=SHILI_D->query_family(slist[sizeof(slist)-2]);
        if((opfaname!="")&&(opfaname==faname)){
                message_vision("$n对$N说，由于贵门多年照顾，就收您一半的钱了.\n",me,owner);
                price=price/2;
        }
        if((opfaname!="")&&faname&&(FAMILYD->family_relation(opfaname,faname)==-1)){
                message_vision("$n对$N说，"+SHILI_D->query_master(opfaname)+"说了，卖给贵门派弟子的东西，价格都要翻倍。\n",me,owner);
                price=price*2;
        }
        
        if( afford = me->can_afford(price) ) {
          if( afford==2 ) 
                           return notify_fail("你没有足够的零钱，而银票又没人找得开。\n");

                if(owner->complete_trade(me, item)) {
                  me->pay_money(price);
                  return 1;
                } else {
                    return 0;
                }
        } else
                return notify_fail("你的钱不够。\n");
}

int help(object me)
{
   write( @HELP
指令格式: buy <something> from <someone>

这一指令让你可以从某些人身上买到物品。
HELP
   );
   return 1;
}
