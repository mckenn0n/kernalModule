#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/list.h>


struct birthday{
	int day, month, year;
	struct list_head list;
};

static LIST_HEAD(birthday_list);

struct birthday *person;

person = kmalloc(sizeof(*person), GFP_KERNEL);
person->day = 19;
person->month = 3;
person->year = 1995;
INIT_LIST_HEAD(&person->list);

list_add_tail(&person->list, &birthday_list)

int simple_init(void)
{
       printk(KERN_INFO "Loading Module\n");

       return 0;
}

void simple_exit(void) {
	printk(KERN_INFO "Removing Module\n");
}

module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");