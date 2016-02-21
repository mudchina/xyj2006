//  fabao_status.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
   object ob;
   string ob_id;
   object *inv;
   mapping fabao;
   int  i;
   string series_no;
   
    seteuid(getuid());
    
    if(!arg)
       ob = me; 
    else  {
       ob = find_player(arg);
       if( !ob )  ob = find_living(arg);
       if( !ob )  return notify_fail("你要察看谁的法宝状态？\n");
    }
    
    if( ob!=me && !wizardp(me) )
       return notify_fail("只有巫师能察看他人的法宝状态。\n"); 

    fabao = ob->query("fabao");
    if( !mapp(fabao) )
       return notify_fail(ob->query("name")+"目前没有任何法宝。\n");           
 
    inv = all_inventory(ob);
    ob_id = getuid(ob);
    for(i=0; i<sizeof(inv); i++)  { 
       if( (series_no=inv[i]->query("series_no")) &&
        inv[i]->query("owner_id") == ob_id ) {
		   if( series_no == "1" )  {
              write(sprintf("%s伤害力为 %d。\n", inv[i]->query("name"),
                 inv[i]->query("weapon_prop/damage") ));
           }
		   else if( series_no == "2" || series_no == "3" )  {
              write(sprintf("%s防御力为 %d。\n", inv[i]->query("name"),
                  inv[i]->query("armor_prop/dodge") ));
              write(sprintf("%s抵抗力为 %d。\n", inv[i]->query("name"),
                  inv[i]->query("armor_prop/armor") ));
              write(sprintf("%s内功抵抗力为 %d。\n", inv[i]->query("name"),
                  inv[i]->query("armor_prop/armor_vs_force") ));
              write(sprintf("%s魔法攻击力为 %d。\n", inv[i]->query("name"),
                  inv[i]->query("armor_prop/spells") ));
              write(sprintf("%s魔法抵抗力为 %d。\n", inv[i]->query("name"),
                  inv[i]->query("armor_prop/armor_vs_spells") ));
          } 
       }
    }
    
    return 1;          
}

int help(object me)
{
        write(@HELP
指令格式 : fabao_status [<某人>]

这个指令可以让你查询法宝状态。

巫师可以查询任何人的法宝状况。

HELP
    );
    return 1;
}

