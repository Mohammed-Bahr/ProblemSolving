use std::collections::HashMap;

struct Solution;

impl Solution {

    fn dfs(
        adj_list: &mut HashMap<String, Vec<String>>,
        current: String,
        itinerary: &mut Vec<String>,
    ) {

        while let Some(destinations) = adj_list.get_mut(&current) {

            if destinations.is_empty() {
                break;
            }

            // smallest lexical destination
            let next_city = destinations.remove(0);

            Self::dfs(adj_list, next_city, itinerary);
        }

        itinerary.push(current);
    }

    fn find_itinerary(tickets: Vec<Vec<String>>) -> Vec<String> {

        let mut adj_list: HashMap<String, Vec<String>> = HashMap::new();

        // build graph
        for ticket in tickets {

            let src = ticket[0].clone();
            let dst = ticket[1].clone();

            adj_list
                .entry(src)
                .or_insert(Vec::new())
                .push(dst);
        }

        // sort destinations lexicographically
        for destinations in adj_list.values_mut() {
            destinations.sort();
        }

        let mut itinerary: Vec<String> = Vec::new();

        Self::dfs(
            &mut adj_list,
            "JFK".to_string(),
            &mut itinerary,
        );

        itinerary.reverse();

        itinerary
    }
}

fn main() {

    let tickets = vec![
        vec!["JFK".to_string(), "SFO".to_string()],
        vec!["JFK".to_string(), "ATL".to_string()],
        vec!["SFO".to_string(), "ATL".to_string()],
        vec!["ATL".to_string(), "JFK".to_string()],
        vec!["ATL".to_string(), "SFO".to_string()],
    ];

    let itinerary = Solution::find_itinerary(tickets);

    for city in itinerary {
        print!("{} ", city);
    }

    println!();
}
