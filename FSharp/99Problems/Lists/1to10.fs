namespace Lists

// https://wiki.haskell.org/99_questions/1_to_10
module _1to10 =
    let Last = List.last
    let Penultimate l = List.rev l |> List.skip 1 |> List.head
    let Kth k l = l |> List.skip (k - 1) |> List.head
    let Length = List.length
    let Reverse = List.rev
    let Palindrome l = l = Reverse l

    // define list of lists
    type LoL<'T> =
        | V of 'T
        | L of LoL<'T> list
    let rec Flatten (lol: LoL<'T>) =
        match lol with
        | V v -> [v]
        | L l -> List.fold (fun acc a -> acc@(Flatten a)) [] l

    let Compress (l:List<'T>) = List.fold (fun acc a -> acc@(if a = (List.last acc) then [] else [a])) [l.Head] l
    //let Pack (l:List<'T>) = 