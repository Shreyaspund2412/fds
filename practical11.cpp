#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Job {
    int id;
    string description;

    Job(int jobId, const string& jobDescription)
        : id(jobId), description(jobDescription) {}
};

class JobQueue {
private:
    queue<Job> jobQueue; // Renamed to avoid confusion with the standard queue

    int nextJobId = 1;

public:
    void addJob(const string& description) {
        Job newJob(nextJobId++, description);
        jobQueue.push(newJob);
        cout << "Job added: " << newJob.id << " - " << newJob.description << endl;
    }

    void deleteJob() {
        if (jobQueue.empty()) {
            cout << "No jobs to delete.\n";
        } else {
            Job job = jobQueue.front();
            jobQueue.pop();
            cout << "Job deleted: " << job.id << " - " << job.description << endl;
        }
    }

    void displayJobs() {
        if (jobQueue.empty()) {
            cout << "No jobs in queue.\n";
        } else {
            queue<Job> tempQueue = jobQueue; // Copy of the queue to display without modifying original queue
            while (!tempQueue.empty()) {
                Job job = tempQueue.front();
                cout << "Job ID: " << job.id << ", Description: " << job.description << endl;
                tempQueue.pop();
            }
        }
    }
};

int main() {
    JobQueue jobQueue;
    jobQueue.addJob("Process data");
    jobQueue.addJob("Generate report");
    jobQueue.displayJobs();
    jobQueue.deleteJob();
    jobQueue.displayJobs();

    return 0;
}
