#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/list.h>


struct birthday{
	int day, month, year;
	struct list_head list;
};



int simple_init(void){
	static LIST_HEAD(birthday_list);

	struct birthday *person;
	struct birthday *personTwo;
	struct birthday *personThree;
	struct birthday *personFour;
	struct birthday *personFive;

	person = kmalloc(sizeof(*person), GFP_KERNEL);
	person->day = 19;
	person->month = 3;
	person->year = 1992;
	INIT_LIST_HEAD(&person->list);

	list_add_tail(&person->list, &birthday_list);

	personTwo = kmalloc(sizeof(*personTwo), GFP_KERNEL);
	personTwo->day = 12;
	personTwo->month = 7;
	personTwo->year = 1995;
	INIT_LIST_HEAD(&personTwo->list);

	list_add_tail(&personTwo->list, &birthday_list);

	personThree = kmalloc(sizeof(*personThree), GFP_KERNEL);
	personThree->day = 23;
	personThree->month = 5;
	personThree->year = 1985;
	INIT_LIST_HEAD(&personThree->list);

	list_add_tail(&personThree->list, &birthday_list);

	personFour = kmalloc(sizeof(*personFour), GFP_KERNEL);
	personFour->day = 13;
	personFour->month = 6;
	personFour->year = 1999;
	INIT_LIST_HEAD(&personFour->list);

	list_add_tail(&personFour->list, &birthday_list);

	personFive = kmalloc(sizeof(*personFive), GFP_KERNEL);
	personFive->day = 1;
	personFive->month = 1;
	personFive->year = 2000;
	INIT_LIST_HEAD(&personFive->list);

	list_add_tail(&personFive->list, &birthday_list);


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