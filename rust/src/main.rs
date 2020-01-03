use std::convert::TryInto;

fn main() {
    println!("Hello, world!");

    let v = vec![0,1,2,3,5,7,14,29,30,33];
    let index = binary_search(v, 3);
    if index == -1 {
        println!("target not found");
    }
    else {
        println!("target found at index {}", index);
    }
}

fn binary_search(data:Vec<i32>, key:i32) -> isize {
    let mut search_index :usize = 0;
    let mut min_index :usize = 0;
    let mut max_index :usize = data.len() - 1;
    let mut found_index :isize = -1;

    while (max_index - min_index) > 1 {
        search_index = get_next_search_index(min_index, max_index);

        if data[min_index] == key {
            found_index = min_index.try_into().unwrap();
            break;
        }
        else if data[search_index] == key {
            found_index = search_index.try_into().unwrap();
            break;
        }
        else if data[search_index] > key {
            max_index = search_index;
        }
        else if data[search_index] < key {
            min_index = search_index;
        }
    }

    return found_index;
}

fn get_next_search_index(min_index :usize, max_index :usize) -> usize {
    let mut search_index :usize = 0;
    if (max_index - min_index) == 2 {
        search_index = min_index + 1;
    }
    else {
        search_index = ( (max_index-min_index) / 2 ) + min_index;
    }
    println!("searching at index: {}", search_index);

    return search_index;
}
