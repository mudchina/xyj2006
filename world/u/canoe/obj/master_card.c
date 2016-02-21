#include <ansi.h>
inherit ITEM;
string money_str(int amount);
int pay_player(object who, int amount);
int help(object me);
void create()
{
        set_name(HIY"´óÌÆ½ğÁú¿¨"NOR, ({"master card","card"}) );
        set_weight(10);
        set("no_get",1);
        set("no_drop","ÕâÃ´¹óÖØµÄ¶«Î÷ÔõÃ´ÄÜ¶ªµôÄØ¡£\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ÕÅ");
                set("material", "steal");
                set("long", "
            [1;33m    ´óÌÆ½ğÁú¿¨(Master card)[m   
¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù
¡ù               [0;1;37;40m  Äú¿ÉÒÔÊ¹ÓÃÈçÏÂÃüÁî£º[m                    ¡ù
¡ù     È¡Ç®£º    ÃüÁî¸ñÊ½£ºwithdraw <ÊıÁ¿> <»õ±Òµ¥Î»>   ¡ù
¡ù     È¡Ç±ÄÜ£º  ÃüÁî¸ñÊ½£ºwithdraw <ÊıÁ¿> Ç±ÄÜ         ¡ù
¡ù     ´æÇ®£º    ÃüÁî¸ñÊ½£ºdeposit  <ÊıÁ¿> <»õ±Òµ¥Î»>   ¡ù
¡ù     ´æÇ±ÄÜ£º  ÃüÁî¸ñÊ½£ºdeposit  <ÊıÁ¿> Ç±ÄÜ¡£       ¡ù
¡ù     ²éÑ¯Óà¶î£ºÃüÁî¸ñÊ½£ºbank                         ¡ù
¡ù     [0;1;37;34mÎ÷ÓÎ¼Ç2006µÄÍ¨ÓÃĞÅÓÃ¿¨£¬´ú±í×ÅÄãÔÚ±¾Õ¾µÄĞÅÓş¡£ [m    ¡ù
¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù
");         
   }
}

void init()
{
        object me = this_object();
        object who = this_player();
        object where = environment();
        if (! me->query("my_owner") &&
             interactive (who))
        me->set("my_owner",who->query("id"));
       if (userp(where))
        {
         if (me->query("owned"))
           {
            if (me->query("owned")!=where->query("id"))
                  call_out("destruct_me",1,where,me);
           }
         else me->set("owned",where->query("id"));
       }
        add_action("do_deposit","deposit");
        add_action("do_withdraw","withdraw");
        add_action("do_check", "bank");
}
int do_deposit(string arg)
{
        string what;
        int amount;
        object what_ob, me;

        me = this_player();
        if( me->is_busy()||me->is_fight())
            return notify_fail("ÄãÏÖÔÚÕıÃ¦×ÅÄØ...¡£\n");
        
        if(arg && sscanf(arg, "%d %s", amount, what)==2)
        {
        if (what=="Ç±ÄÜ")
        {
        if (amount < 1||me->query("potential")-me->query("learned_points") < 1)
                  return notify_fail("ÄãÏë´æ¶àÉÙÇ±ÄÜ£¿\n");
        if (amount>me->query("potential")-me->query("learned_points"))
                  return notify_fail("ÄãµÄÇ±ÄÜ²»¹»´æ¡£\n");
        me->start_busy(1);
        message_vision(sprintf("$NÄÃ³ö%sµãÇ±ÄÜ£¬´æ½øÁË"HIY"´óÌÆ½ğÁú¿¨"NOR"¡£\n",
                       chinese_number(amount)), me);
        me->add("c_potential", amount*9/10);
        me->add("potential",-amount);
        me->save();
        return 1;
        }
        else what_ob = present(what + "_money", me);
        if (!what_ob)  
             return notify_fail("ÄãÉíÉÏÃ»ÓĞ´øÕâÖÖÇ®¡£\n");
        if (amount < 1)
             return notify_fail("ÄãÏë´æ¶àÉÙ" + what_ob->query("name") + "£¿\n");
        if ((int)what_ob->query_amount() < amount)
             return notify_fail("Äã´øµÄ" + what_ob->query("name") + "²»¹»¡£\n");
        me->start_busy(1);
        message_vision(sprintf("$NÄÃ³ö%s%s%s£¬´æ½øÁË"HIY"´óÌÆ½ğÁú¿¨"NOR"¡£\n",
                chinese_number(amount), what_ob->query("base_unit"),
                what_ob->query("name")), me);
        me->add("c_balance", what_ob->query("base_value") * amount);
        if ((int)what_ob->query_amount() == amount)
            destruct(what_ob);
        else
            what_ob->add_amount(-amount);
        me->save();
        return 1;
        }
        else return help(me);
}
 
int do_check()
{
   int total = (int)this_player()->query("c_balance");

   if(!total || total < 0)  {
        this_player()->set("c_balance", 0);
        write("ÄúÕâÕÅ¿¨ÉÏÒÑ¾­Ã»Ç®ÁË¡£\n");
   }
   else write("Äú¿¨ÖĞÄ¿Ç°»¹ÓĞ" + money_str(total) + "Óà¶î¡£\n");
   total = (int)this_player()->query("c_potential");
   if(!total || total < 0)  {
        this_player()->set("c_potential", 0);
        return notify_fail("ÄúÕâÕÅ¿¨ÉÏÃ»ÓĞÈÎºÎÇ±ÄÜÓà¶î¡£\n");
   }
   write("Äú¿¨ÖĞÄ¿Ç°»¹ÓĞ" + chinese_number(total)+ "µãÇ±ÄÜÓà¶î¡£\n");
   return 1;
}

int do_withdraw(string arg)
{
        int amount, v, rv;
        string what;
        object me;

        me = this_player();
        if( me->is_busy()||me->is_fight())
            return notify_fail("ÄãÏÖÔÚÕıÃ¦×ÅÄØ...¡£\n");

        if (arg && sscanf(arg, "%d %s", amount, what) == 2)
        {
        if (amount < 1)
                   return notify_fail("ÄãÏëÈ¡¶àÉÙ£¿\n");
        if(what=="Ç±ÄÜ")
        {
        if (amount > me->query("c_potential"))
                     return notify_fail("Äã¿¨ÀïµÄÇ±ÄÜ²»¹»È¡¡£\n");
        me->start_busy(1);
        me->add("c_potential",-amount);
        me->add("potential",amount);
        me->save();
        message_vision(sprintf("$N´Ó"HIY"´óÌÆ½ğÁú¿¨"NOR"ÀïÈ¡³ö%sµãÇ±ÄÜ¡£\n", 
                      chinese_number(amount)),me);
        return 1;
        }
        else if (file_size("/obj/money/" + what + ".c") < 0)
                   return notify_fail("ÄãÏëÈ¡³öÊ²Ã´Ç®£¿\n");
        what = "/obj/money/" + what;
        if ((v = amount * what->query("base_value")) > me->query("c_balance"))
                   return notify_fail("Äã¿¨ÀïµÄÇ®²»¹»È¡¡£\n");
        if( v < what->query("base_value") ) 
                   return notify_fail("²»ÒªÕâÑù×ö£¬²»È»¡£¡£¡££¡\n");
        me->start_busy(1);
        rv = v;
        v=v-pay_player(me, rv);
        me->add("c_balance",  -v);
        me->save();
        message_vision(sprintf("$N´Ó"HIY"´óÌÆ½ğÁú¿¨"NOR"ÀïÈ¡³ö%s¡£\n", money_str(v)),
                me);
        return 1;
        }
        else return help(me);
}

string money_str(int amount)
{        
       string output;
        if (amount / 10000) {
                output = chinese_number(amount / 10000) + "Á½»Æ½ğ";
                amount %= 10000;
        }
        else
                output = "";
        if (amount / 100) {
                output = output + chinese_number(amount / 100) + "Á½°×Òø";
                amount %= 100;
        }
        if (amount || sizeof(output)<2)
                return output + chinese_number(amount) + "ÎÄÍ­°å";
        return output;
}
int pay_player(object who, int amount)
{
        int v;
        object ob;

        seteuid(getuid());
        if (amount < 1)
                amount = 0;
        if (v = amount / 10000) {
                ob = new("/obj/money/gold");
                ob->set_amount(amount / 10000);
                if(!(ob->move(who)))
                    return amount;
                amount %= 10000;
        }
        if (amount / 100) {
                ob = new("/obj/money/silver");
                ob->set_amount(amount / 100);
                if(!(ob->move(who)))
                    return amount;
                amount %= 100;
        }
        if (amount) {
                ob = new("/obj/money/coin");
                ob->set_amount(amount);
                if(!(ob->move(who)))
                    return amount;
        }
        return 0;
}
int help(object me)
{
write(@HELP
        
È¡Ç®£º  ÃüÁî¸ñÊ½£ºwithdraw <ÊıÁ¿> <»õ±Òµ¥Î»>
È¡Ç±ÄÜ£ºÃüÁî¸ñÊ½£ºwithdraw <ÊıÁ¿> Ç±ÄÜ
´æÇ®£º  ÃüÁî¸ñÊ½£ºdeposit  <ÊıÁ¿> <»õ±Òµ¥Î»>
´æÇ±ÄÜ£ºÃüÁî¸ñÊ½£ºdeposit  <ÊıÁ¿> Ç±ÄÜ
²éÑ¯Óà¶î£ºÃüÁî¸ñÊ½£ºbank 
HELP
    );
    return 1;
}

void destruct_me(object where, object me)
{
  message_vision("Ç§Ãæ¹Ö¹í¹íËîËîµØÄÃÆğ$nÈö½Å¾ÍÅÜ£¬¿ì×·£¡\n",where,me);
  destruct (me);
}
int query_autoload() { return 1; }      
