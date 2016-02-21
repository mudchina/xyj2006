// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
// user list
// by canoe 2001.08.24

int help(object me);
inherit F_CLEAN_UP;

int main(object me,string arg)
{
        object *ob;
        int i,flag;
        string str;
        if(arg && sscanf(arg,"number %s",str)==1)
        {
        ob=users();
        i = sizeof(ob);
        flag=1;
        while (i--)
        	{
        	if (str==file_name(ob[i]))
        		{
        		write(sprintf("ÓÃ»§ÎÄ¼şÃûÎª[1;33m%s[mµÄÍæ¼ÒÊÇ[1;33m%s [m¡£ \n",
        		file_name(ob[i]),ob[i]->query("id")));
        		flag=0;
        		}
        	}
       if(flag) return notify_fail("¶Ô²»Æğ£¬²éÎŞ´ËÈË¡£\n");
       return 1; 
	}
	else if(arg && sscanf(arg,"id %s",str)==1)
       {
     	if(!find_player(str))
       		return notify_fail("¶Ô²»Æğ£¬²éÎŞ´ËÈË¡£\n");
      	write(sprintf("Íæ¼Ò[1;33m%s[mµÄÓÃ»§ÎÄ¼şÃûÊÇ[1;33m%s[m¡£\n",str,file_name(find_player(str))));
        return 1; 
	}
	else return help(me); 
}

int help(object me)
{
write(@HELP
[1;37m  
×÷    ÓÃ£ºÁĞ³öÍæ¼ÒµÄuser number¡£
[1;33m 
Ö¸Áî¸ñÊ½£ºulist1 number <Íæ¼ÒÎÄ¼şÃû>
         ulist1 id     <Íæ¼Òid>
[1;37m        
ÀıÈç£ºÍæ¼Òcanoe µÄuser number Îª/obj/user#1
[1;33m 
 1¡¢  ÓÃulist1 number /obj/user#1 ,ÔòÏÔÊ¾ 
      ÓÃ»§ÎÄ¼şÃûÎª/obj/user#1µÄÍæ¼ÒÊÇcanoe¡£
      
 2¡¢  ÓÃulist1 id canoe ,ÔòÏÔÊ¾ 
      Íæ¼ÒcanoeÓÃ»§ÎÄ¼şÃûÎª/obj/user#1¡£    
[0;1;37;34m       
¶Ô¸¶³ö´íĞÅÏ¢±È½ÏÓĞÓÃ¡£
[m
HELP
    );
    return 1;
}
