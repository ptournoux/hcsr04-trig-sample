#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/sensor.h>
#include <string.h>
#define LOG_LEVEL CONFIG_LOG_DEFAULT_LEVEL
#include <zephyr/logging/log.h>


const struct device *const dev = DEVICE_DT_GET_ONE(hcsr04trig);


int main(void)
{

    if (dev == NULL) {
        printk("Error: HCSR04TRIG device not found\n");
        return -1;
    }

    if (!device_is_ready(dev)) {
		printk("\nError: Device \"%s\" is not ready; "
		       "check the driver initialization logs for errors.\n",
		       dev->name);
		return -90;
	}

    printk("HCSR04TRIG device found and ready\n");

    while (1) {

        struct sensor_value distance;
        int ret = sensor_sample_fetch(dev);
        if (ret < 0) {
            printk("Error: sensor_sample_fetch failed: %d\n", ret);
            continue;
        }

        ret = sensor_channel_get(dev, SENSOR_CHAN_DISTANCE, &distance);
        if (ret < 0) {
            printk("Error: sensor_channel_get failed: %d\n", ret);
            continue;
        }

        printk("Distance: %d.%d m\n", distance.val1,distance.val2);

	    k_sleep(K_MSEC(1000)); // Sample every 1 second
    }

}
