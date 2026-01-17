 #include "high_scores.h"

void copy_scores(const int32_t *scores, size_t scores_len, int32_t *temp_scores)
{
    int i, len = (int)scores_len;
    for(i = 0; i < len; i++)
    {
        temp_scores[i] = scores[i];
    }
}

int compare_desc(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x > y) return -1;
    if (x < y) return 1;
    return 0;
}

int32_t *sorted_copy(const int32_t *scores, size_t scores_len)
{
    int32_t *sorted_scores = malloc(sizeof(int32_t) * scores_len);
    if(sorted_scores == NULL) return  NULL;
    copy_scores(scores, scores_len, sorted_scores);
    qsort(sorted_scores, scores_len, sizeof(int32_t), compare_desc);
    return sorted_scores;
}


int32_t latest(const int32_t *scores, size_t scores_len)
{
    return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len)
{
    int32_t *temp_scores = sorted_copy(scores, scores_len);
    int32_t best = temp_scores[0];
    free(temp_scores);
    return best;
}

/// Write the highest scores to `output` (in non-ascending order).
/// Return the number of scores written.
size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output)
{
    int32_t *temp_scores = sorted_copy(scores, scores_len);     

    size_t personal_tops = 0;

    switch (scores_len)
    {
    case 1:
        output[0] = temp_scores[0];
        personal_tops = 1;
        break;
    case 2:
        output[0] = temp_scores[0];
        output[1] = temp_scores[1];
        personal_tops = 2;
        break;
    default:
        output[0] = temp_scores[0];
        output[1] = temp_scores[1];
        output[2] = temp_scores[2];
        personal_tops = 3;
        break;
    }

    free(temp_scores);
    return personal_tops;
}