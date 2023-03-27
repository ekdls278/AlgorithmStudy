import java.util.*

fun main() = with(Scanner(System.`in`)){
    val n = nextInt()
    var arr = arrayListOf<Int>()
    for(i : Int in 0 until n)
    {
        arr.add(nextInt())
    }
    val max = Collections.max(arr)
    val min = Collections.min(arr)

    println("$min $max")
}