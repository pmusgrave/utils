module.exports = function ()
{
    function quicksort(array, low, high) {
        //console.log(array)
        if (low < high) {
            let q = partition(array, low, high);
            quicksort(array, low, q - 1);
            quicksort(array, q + 1, high);
        }
    }

    function partition(array, low, high) {
        let pivot = array[high];
        let i = low - 1;
        for (let j = low; j <= (high-1); j++) {
            if (array[j] <= pivot) {
                i++;
                let temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }

        if (array[high] < array[i + 1]) {
            let temp = array[high];
            array[high] = array[i+1];
            array[i+1] = temp;
        }

        return (i+1);
    }

    return {
        quicksort: quicksort
    }
}();
