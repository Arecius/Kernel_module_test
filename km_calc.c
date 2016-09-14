#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

//MODULE_AUTHOR("Daniel Henriquez");

static int            var_A = 1;
static int            var_B = 1;
static int          opt  = 0;

//MODULE_PARM(var_A, "i");
//MODULE_PARM(var_B, "i");
//MODULE_PARM(operation, "s");

module_param(var_A,int,0);
module_param(var_B,int,0);
module_param(opt, int, 0);

MODULE_PARM_DESC(opt, "Operation to be perfomed");
MODULE_PARM_DESC(var_A, "First Value");
MODULE_PARM_DESC(var_B, "Second Value");



static int __init mdule_init(void)
{
   
   pr_alert("Launching Kernel Module Calc\n");
   switch(opt){
      case 1:
        printk("Operation is Sum\n");
        printk("Result: %i \n ", var_A+var_B);
      break;
      case 2:
        printk("Operation is Subtract\n");
        printk("Result: %i \n", var_A-var_B);
      break;
      case 3:
        printk("Operation is Multplication\n");
        printk("Result: %i \n", var_A*var_B);
      break;
      /*
      case 4:
        printk("Operation is Division\n");
        printk("Result: %f \n", (float)var_A/(float)var_B);
      break;
      */
      default:
        printk("Unknown Operation\n");
      break;
   }

   return 0;
}


static void __exit mdule_exit(void)
{
   pr_alert("Unloading km_calc module\n");
}


module_init(mdule_init);
module_exit(mdule_exit);
